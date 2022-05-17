from sys import argv, exit
from cs50 import get_string

ascii_lowercase = 'abcdefghijklmnopqrstuvwxyz'
ascii_uppercase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
forwards = []

def forward(n):
    for i in n:
        if i.isupper():
            forwards.append(ascii_uppercase.index(i))
        else:
            forwards.append(ascii_lowercase.index(i))
   
   
def forwarded(n):
    forward(argv[1])
    global result
    result = ""
    
    ind = 0
    size  = 0
    if forwards is not None:
        size = len(forwards)
    
    for i in n:
        if ind == size:
            ind = 0
        
        if i.isupper():
            index = ascii_uppercase.index(i)
            new_index = (index + forwards[ind]) % 26
            result += ascii_uppercase[new_index]
            ind += 1
            
        elif i.islower():
            index = ascii_lowercase.index(i)
            new_index = (index + forwards[ind]) % 26
            result += ascii_lowercase[new_index]
            ind += 1
            
        else:
            result += i
            
// function that checks whether keyword contains integer
def check(n):
    for i in n:
        if i.isdigit():
            return True
    return False
    
def main():
    if len(argv) < 2 or check(argv[1]):
      // exit code in python --> sys.exit()
        exit(1)
    else:
        plaintext = get_string("plaintext: ")
        forwarded(plaintext)
        print(f"ciphertext: {result}")
        exit(0)
    
main()
