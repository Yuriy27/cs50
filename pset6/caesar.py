import sys
import cs50

MOD = 26

def is_number(number):
    try:
        int(number)
        return True
    except ValueError:
        return False

def get_base_char(letter):
    if letter.isupper():
        return 'A'
    return 'a'

def encode_char(letter, shift):
    if (letter.isalpha()):
        return chr(ord(get_base_char(letter)) + (ord(letter) - ord(get_base_char(letter)) + int(shift)) % MOD)
    return letter

def cipher_encode(text, shift):
    encoded = "";
    for letter in text:
        encoded += encode_char(letter, shift)
    return encoded

def main(argc, argv):
    if argc != 2:
        print("Usage: caesar.py shift")
        quit()
    if not is_number(argv[1]):
        print("Second param should be a number")
        quit()
    print("plaintext: ", end="");
    text = cs50.get_string()
    shift = argv[1]
    print("ciphertext: %s" % cipher_encode(text, shift))


main(len(sys.argv), sys.argv)
