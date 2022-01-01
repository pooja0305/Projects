films = {
    "Life Of Pie" : [5,5],
    "Tenet" : [18,5],
    "Tom And Jerry" : [3,5],
    "Space Sweepers" : [15,5]
    }

while True:
    choice = input("What film would you like to watch?: ").strip().title()

    if choice in films:
        age = int(input("How old are you?: ").strip())

        #check user age

        if age >= films[choice][0]:

            #check enough seats

            num_seats = films[choice][1]

            if num_seats >0:
             print("Enjoy the film!")

             films[choice][1]=films[choice][1]-1

            else:
                 print("sorry we are sold out")
                 
        else:
            print("You are too young to watch that film!")
        
    
    else:
        print("we don't have that film...")
    



  
                                                                          
