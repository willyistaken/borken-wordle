import random

WORDLEN = 5;

g = ""

def give_question():
    with open("solution.txt") as f:
        s = f.readlines()
        print("Your word is: ", random.choice(s))

def check_allow():
    s = input("enter word:").strip("\n")
    if(s in g):
        print("yes\n")
    else:
        print("no\n")


if __name__=="__main__":
    with open("accept.txt") as f:
        g = f.read()
    while(True):
        print("---------------------------------------------")
        print("1. randomly gives a wordle from answer list")
        print("2. check if a word is allow")
        print("---------------------------------------------")
        t = input("\nYour Choice:")
        if(t=="1"):
            give_question()
        elif(t=="2"):
            check_allow()
        else:
            print("please choose what you want to do")
