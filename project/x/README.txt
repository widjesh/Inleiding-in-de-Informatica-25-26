This is our project for Inleiding Informatica. 
Lecturer: Widjesh Baggan 
Groep members: Chetram Samuel 20250020
               Wangsawirana Yosao 20250676 

# Simple Console Password Manager (C++)

## Overview
We have created a relatively unsecure password manager, but it taught us the basics of C++ programming and the use of different libraries such as `fstream` and `map`.  

The program allows users to store and retrieve passwords for different websites in a simple console interface.

---

## Features
- Master username and password authentication to secure access
- Add new website-password pairs
- View stored passwords
- Passwords are encrypted using a **Caesar Cipher** with a **fixed shift of 17**
- All data is stored in text files (`.txt`) so it persists between program runs
- Menu-driven interface for easy navigation

---

## How It Works
1. **Master Authentication**:  
   - The program first checks if `Master_Authentication.txt` exists.  
   - If not, the user is prompted to create a master username and password, which are then encrypted and stored.  
   - This master credential is required to access and manipulate the stored passwords.

2. **Password Storage**:  
   - All website passwords are stored in `Stored_Passkeys.txt`.  
   - Each password is encrypted using the Caesar Cipher (shift = 17) before being written to the file.  
   - When viewing a password, it is decrypted using the same shift.

3. **Menu Options**:  
   - **Add Password**: Input a website and password; the password is encrypted and stored.  
   - **View Password**: Input a website; the program decrypts and displays the password if it exists.  
   - **Exit**: Close the program.

---

## Files Used
- `password_manager.cpp` — The main source code file.
- `Master_Authentication.txt` — Stores the encrypted master username and password.  
  Format:

- `Stored_Passkeys.txt` — Stores all website-password pairs in encrypted form.  
Format:


---

## Encryption
- Uses a **Caesar Cipher** with a fixed shift of 17.  
- Encrypts uppercase letters, lowercase letters, and digits.  
- Special characters are not encrypted.  
- **Important:** This is **not secure for real-world use**; it is purely for learning purposes.

---

## How to Compile
Make sure you have a C++ compiler (g++, Visual Studio, or CodeBlocks).

```bash
g++ password_manager.cpp -o password_manager
