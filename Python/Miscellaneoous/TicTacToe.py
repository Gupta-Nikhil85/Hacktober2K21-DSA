# TicTacToe game
# Developed by Ratan R. Ojha
# Date: 4th Oct 2021


print("Welcome to tic tac toe","Player 1: X and Player 2: O", sep="\n")

print("Your response must be integer from 1 to 9", "[1,2,3]","[4,5,6]","[7,8,9]",sep="\n")

print("Let the game begin")



input("Press Enter to continue...")

P1='X'

P2='O'



R1=["   ","   ","   "]

R2=["   ","   ","   "]

R3=["   ","   ","   "]

box=[R1,R2,R3]



def checkwin():

    if (box[0]+box[1]+box[2]).count(' '+i+' ')>=3:

        if box[0][0]==box[0][1]==box[0][2]!='':

            return True

        elif box[1][0]==box[1][1]==box[1][2]!='':

            return True

        elif box[2][0]==box[2][1]==box[2][2]!='':

            return True

        elif box[0][0]==box[1][0]==box[2][0]!='':

            return True

        elif box[0][1]==box[1][1]==box[2][1]!='':

            return True

        elif box[0][2]==box[1][2]==box[2][2]!='':

            return True

        elif box[0][0]==box[1][1]==box[2][2]!='':

            return True

        elif box[0][2]==box[1][1]==box[2][0]!='':

            return True

        else:

            return False

    else:

        return False

   
for i in ['X','O','X','O','X','O','X','O','X','O']:

    print("Its the chance of ",i)

    

    T=0

    while T==0:

        try:

            response=int(input("Enter spot to be marked: "))

        except:

            print("Invalid input")

            continue

        if response in [1,2,3,4,5,6,7,8,9]:

            print(box[(response-1)//3][(response-1)%3])

            if box[(response-1)//3][(response-1)%3]=="   ":

                box[(response-1)//3][(response-1)%3]=' '+i+' '

                T=1

            else:

                print("Already marked")

                T=0  

        else:

            print("Invalid input")

            T=0



    print(R1,R2,R3,sep="\n")


    if checkwin():

        print(i,' wins')

        break

    else:

        if '   '  not in R1+R2+R3:

            print("Game is Draw, thanks for playing")

            break

input("Press Enter to exit...")

quit()
