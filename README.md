# SecureVar
in-memory variable encryption library, a library that helps you protecte sensitive information in your executable, by encrypting(XOR) variables to prevent memory editing. 

Features:
- Encrypts variables in memory to make them invisible to memory editors
- After the variable is accessed, it will be re-encrypted with another random generated key.

Todo:
- Checksum and restoration of original variable in case of memory manipulation (something like ECC does for the ram)

![](https://i.imgur.com/h6v9ztb.gif)



