wget -O xc8_installer.run https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/SoftwareTools/xc8-v2.45-full-install-linux-x64-installer.run
chmod +x xc8_installer.run
sudo ./xc8_installer.run --mode unattended --unattendedmodeui none --netservername localhost

sudo visudo
user=$(whoami)

$user ALL=(ALL) NOPASSWD: xc8_installer.run --mode unattended --unattendedmodeui none --netservername some-placeholder-value
sudo xc8_installer.run --mode unattended --unattendedmodeui none --netservername some-placeholder-value