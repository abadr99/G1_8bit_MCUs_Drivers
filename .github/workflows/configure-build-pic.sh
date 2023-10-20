wget -O xc8_installer.run https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/SoftwareTools/xc8-v2.45-full-install-linux-x64-installer.run
chmod +x xc8_installer.run
# user=$(whoami)
# sudo -i
# cp /etc/sudoers /root/sudoers.bak
# visudo
# echo "$user ALL=(ALL) NOPASSWD: xc8_installer.run --mode unattended --unattendedmodeui none --netservername some-placeholder-value" >>  /etc/sudoers
sudo xc8_installer.run --mode unattended --unattendedmodeui none --netservername some-placeholder-value