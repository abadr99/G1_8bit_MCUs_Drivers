#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIOPrivate.h"
#include "../../../mcal/GPIO/GPIO.h"

#include "Linked_Stack.h"
#include  "Calculator.h"

Calc_Error_t GetPostfixExp(uint8_t pInfixExp[], uint8_t pPostfixExp[])
{
	Calc_Error_t kErrorState = NoError;
    Stack_t Calc_stack;
    int iterator1 = 0;
    int iterator2 = 0;
    LinkedStack_creatStack(&Calc_stack);
    SeparateExp(pInfixExp);

    /**
     * Handle Case if the used enter a sign '+' or '-' before the first number.
     * 
     * assume the Expression : "-5+3"
     *  after we call SeparateExp function the expression will be : " - 5 + 3"
     *  so we check index number 1 instead of 0. 
     * 
     * iterator = 2 --> to skip the first sign at the infix expression
     *  so the expression be like " 5 + 3"
     * 
     */
    if (pInfixExp[1] == '+')
    {
    	iterator1 = 2;
    }else if (pInfixExp[1] == '-')
    {
    	kErrorState = _1stNumIsNeg;
    	iterator1 = 2;
    }
    while(pInfixExp[iterator1] != '\0')
    {
    	/* Case value is Number --> add it to the Post fix expression*/
        if( !IsOperator(pInfixExp[iterator1]) )
        {
            pPostfixExp[iterator2++] = pInfixExp[iterator1++];
        }
        /* case value is operator or space */
        else
        {
            if ( LinkedStack_IsEmpty(&Calc_stack)   )
            {
                LinkedStack_Push(&Calc_stack , pInfixExp[iterator1++]);

            }
            /**
             *  Case operator is a Low Priority operator [ + , - ]
             *    Pop all the operator from the stack. 
             */
            else if ( !IsHighPriority((pInfixExp[iterator1])) )
            {
                while( !LinkedStack_IsEmpty(&Calc_stack) )
                {
                    pPostfixExp[iterator2++] = (uint8_t)LinkedStack_Pop(&Calc_stack);
                }
                LinkedStack_Push(&Calc_stack , pInfixExp[iterator1++]);
            }
            /**
             *  Case operator is a High Priority operator [ * , / ]
             *    Pop only high priority operator from the stack. 
             */
            else
            {
                while( !LinkedStack_IsEmpty(&Calc_stack) && IsHighPriority( LinkedStack_GetTop(&Calc_stack) ) )
                {
                    pPostfixExp[iterator2++] = (uint8_t)LinkedStack_Pop(&Calc_stack);
                }
                LinkedStack_Push(&Calc_stack , pInfixExp[iterator1++]);
            }
        }
    }
    /**
     * Popping all the operators that remain in the stack 
     */
    while( !LinkedStack_IsEmpty(&Calc_stack) )
    {
            pPostfixExp[iterator2++] = (uint8_t)LinkedStack_Pop(&Calc_stack);
    }
    return kErrorState;
}

Calc_Error_t EvaluatePostfixExp(uint8_t pPostfixExp[] , f32_t *pResult, Calc_Error_t PostfixState)
{
	Calc_Error_t retErrorState  = NoError;
	Stack_t Calc_stack;
    uint16 iterator1 = 0;
    uint16 iterator2 = 0;
    uint8_t Num_Arr[6]={};
    bool_t NegFlag = kFALSE;
    f32_t operand1 = 0;
    f32_t operand2 = 0;
    f32_t result = 0;
    /* Handle case if the first number of the expression is Negative */
    if (PostfixState == _1stNumIsNeg)
    {
    	NegFlag = kTRUE;
    }

    /* Creat the stack  */
    LinkedStack_creatStack(&Calc_stack);

    while ( pPostfixExp[iterator1] != '\0')
    {
        uint16 Num = 0;
        if(IsNumber( pPostfixExp[iterator1] ) )
        {
            /**
             * case the number is a  multi digit number
             *  add all the number digit to the Num_Arr 
             */
            while( IsNumber( pPostfixExp[iterator1] ))
            {
                Num_Arr[iterator2++] = pPostfixExp[iterator1];
                iterator1++;
            }
            /**
             * convert the number form string form to a decimal'integer' form
             *   by using ConvertStringToInteger() function.
             * Example:
             *  Num_Arr = "5413"string
             *  after calling the function
             *  Num = (5413)decimal     
             */
            Num = ConvertStringToInteger(Num_Arr, iterator2);
            iterator2 = 0;
            LinkedStack_Push(&Calc_stack, Num);

        }else if ( IsOperator(pPostfixExp[iterator1]))
        {

            operand2 = LinkedStack_Pop(&Calc_stack);
            operand1 = LinkedStack_Pop(&Calc_stack);

            if( NegFlag == kTRUE){
            	operand1 *= -1.0;
            	NegFlag = kFALSE;
            }
            if(operand2 == 0 && pPostfixExp[iterator1] == '/'){
            	retErrorState = DivideByZero;
            	break;
            }
            result = GetResult(operand1, operand2, pPostfixExp[iterator1]);
            LinkedStack_Push(&Calc_stack, result);
            iterator1++;
        }else
        {
            iterator1++;
        }
    }
    if (LinkedStack_GetSize(&Calc_stack) == 1)
    {

    	*pResult = LinkedStack_Pop(&Calc_stack);
    	/*Case if the user enter only one negative number */
    	if ( NegFlag == kTRUE)
    	{
    		*pResult *= -1;
    	}

    }else if(retErrorState != DivideByZero )
    {
    	retErrorState  = SyntaxError;
    }
    return retErrorState;


}

bool_t IsOperator(uint8_t character)
{
	bool_t returnState = kFALSE;
	if ( character == '+' || character == '-' ||
		 character == '*' || character == '/'	){

		returnState = kTRUE;
	}
	return returnState;
}
bool_t IsNumber(uint8_t character)
{
	bool_t returnState = kFALSE;
	if ( character >='0' && character <='9'){
		returnState = kTRUE;
	}
	return returnState;
}

void SeparateExp(uint8_t pExp[])
{
    int interator1 = 0;
    int interator2 = 0;
    uint8_t TempExp[EXPRESSION_SIZE]={};

    while(pExp[interator1] != '\0'){
        TempExp[interator1] = pExp[interator1];
        interator1++;
    }
    interator1 = 0;
    while(TempExp[interator1] != '\0'){

        if( IsOperator(TempExp[interator1]) ){
          pExp[interator2++] = ' ';
          pExp[interator2++] = TempExp[interator1++];
          pExp[interator2++] = ' ';

        }else {
          pExp[interator2++] = TempExp[interator1++];
        }
    }
}
uint16 ConvertStringToInteger(uint8_t strNum[], uint8_t size)
{
	uint16 IntegerNum = 0;
	uint16 iterator = 0;
	for(iterator=0 ; iterator<size ; iterator++){
		IntegerNum *=10;
		IntegerNum += strNum[iterator]-'0';
	}
	return IntegerNum;
}
f32_t GetResult(f32_t _1stNum, f32_t _2ndNum, uint8_t operator)
{
	f32_t result = 0;
	switch (operator){
		case '+': result = _1stNum + _2ndNum; break;
		case '-': result = _1stNum - _2ndNum; break;
		case '*': result = _1stNum * _2ndNum; break;
		case '/': result = _1stNum / _2ndNum; break;
	}
	return result;
}

bool_t IsHighPriority(uint8_t operator)
{
	uint8_t HighPriorityFlag = kFALSE;
	if ( operator == '*' || operator == '/'){
		HighPriorityFlag = kTRUE;
	}
	return HighPriorityFlag;
}