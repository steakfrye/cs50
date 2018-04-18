#creates a simple cipher based on a user's input

import sys
from cs50 import get_string

#if user did not give a proper argument, error
if not len(sys.argv) == 2:
    print("Error")
    exit(1)

#get key and text from user
elif len(sys.argv) == 2:
    key = int(sys.argv[1])
    text = get_string("plaintext: ")

    #prepare to print cipher
    print("ciphertext: ", end="")
    for i in range(len(text)):
        ltr = text[i]

        while ltr.isupper():
            #convert letter to integer and wrap around alphabet
            cipher_ltr = (ord(ltr) - 65 + key) % 26
            cipher_ltr += 65 #return its case
            print(chr(cipher_ltr), end="") #print it back as a letter
            break

        while ltr.islower():
            cipher_ltr = (ord(ltr) - 97 + key) % 26
            cipher_ltr += 97
            print(chr(cipher_ltr), end="")
            break

        #if character is not a letter, print as is
        if not ltr.isalpha():
            print(ltr, end="")
    print()
    exit(0)