import socket

choose = True
while choose:
    print("\nMenu \n1: Get host by name \n2: Get host by address\n3: Quit")
    choose = input("\nEnter your choice: ")

    if choose == "1":
        a = input("\nEnter the URL: ")
        addr1 = socket.gethostbyname(a)
        print("IP address is", addr1)

    elif choose == "2":
        b = input("\nEnter IP: ")
        addr2 = socket.gethostbyaddr(b)
        print("URL is", addr2)

    elif choose == "3":
        exit()

    else:
        print("\nInvalid choice\n")
