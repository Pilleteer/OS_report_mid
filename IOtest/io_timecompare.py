import time

#counting
n=int(input("Enter a number(more than 100000 to make time compare clearer):"))
start_not_io=time.time()
cnt=0
for i in range(n):
    cnt+=1
end_not_io=time.time()
print("Counting time:",end_not_io-start_not_io)

#I/O write
start_io=time.time()
with open("test.txt","w") as f:
    for i in range(n):
        f.write(str(i))
end_io=time.time()
print("I/O write time:",end_io-start_io)

#I/O read
start_io=time.time()
with open("test.txt","r") as f:
    for i in range(n):
        f.read()
end_io=time.time()
print("I/O read time:",end_io-start_io)