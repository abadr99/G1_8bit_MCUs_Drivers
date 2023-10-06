#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../common/test.h"
#include "../../../utils/stack/stack.h"


int main()
{
    // ------------- CHAR STACK
    charStack_t CS;
    
    print_str("Char Stack:\n");
    charStack_Init(&CS);
    
    print_str("sizeof stack member:");
    print_num(sizeof(CS.stackArr[0])); // 1byte
    
    print_str("\nsize: ");
    print_num(charStack_GetSize(&CS)); // Expected 0
    print_str("\ntop: ");
    print_num(CS.top);  // Expected 0
    
    charStack_Push(&CS, 'a');
    charStack_Push(&CS, 'b');
    charStack_Push(&CS, 'c');
    
    print_str("\nsize: ");
    print_num(charStack_GetSize(&CS)); // Expected 3
    print_str("\ntop-val: ");
    print_char(charStack_GetTop(&CS));  // Expected 'c'
    
    charStack_Pop(&CS);
    print_str("\nsize: ");
    print_num(charStack_GetSize(&CS)); // Expected 2
    print_str("\ntop-val: ");
    print_char(charStack_GetTop(&CS));  // Expected 'b'

    charStack_Pop(&CS);
    print_str("\nsize: ");
    print_num(charStack_GetSize(&CS)); // Expected 1
    print_str("\ntop-val: ");
    print_char(charStack_GetTop(&CS));  // Expected 'a'

    charStack_Pop(&CS);
    print_str("\nsize: ");
    print_num(charStack_GetSize(&CS)); // Expected 0

    print_str("\n");

    // ------------- INT STACK
    uint32_tStack_t IS;
    print_str("\nINT Stack:\n");
    uint32_tStack_Init(&IS);
    print_str("sizeof stack member:");
    print_num(sizeof(IS.stackArr[0])); // 4byte
    print_str("\nStack members\n");
    print_str("size: ");
    print_num(uint32_tStack_GetSize(&IS)); // Expected 0
    print_str("\ntop: ");
    print_num(IS.top);  // Expected 0
    
    uint32_tStack_Push(&IS, 100);
    uint32_tStack_Push(&IS, 200);
    uint32_tStack_Push(&IS, 230);
    
    print_str("\nsize: ");
    print_num(uint32_tStack_GetSize(&IS)); // Expected 3
    print_str("\ntop-val: ");
    print_num(uint32_tStack_GetTop(&IS));  // Expected '230'
    
    uint32_tStack_Pop(&IS);
    print_str("\nsize: ");
    print_num(uint32_tStack_GetSize(&IS)); // Expected 2
    print_str("\ntop-val: ");
    print_num(uint32_tStack_GetTop(&IS));  // Expected '200'

    uint32_tStack_Pop(&IS);
    print_str("\nsize: ");
    print_num(uint32_tStack_GetSize(&IS)); // Expected 1
    print_str("\ntop-val: ");
    print_num(uint32_tStack_GetTop(&IS));  // Expected '100'

    uint32_tStack_Pop(&IS);
    print_str("\nsize: ");
    print_num(uint32_tStack_GetSize(&IS)); // Expected 0
}
