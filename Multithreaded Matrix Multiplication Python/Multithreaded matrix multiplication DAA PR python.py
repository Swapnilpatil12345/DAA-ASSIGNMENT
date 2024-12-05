import threading

result=[[0,0],[0,0]]
def multiply_elements(A,B,i,j):
    result[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j]

def main():
    A=[[1,2],[3,4]]
    B=[[5,6],[7,8]]

    threads=[]

    for i in range(2):
        for j in range(2):
            thread = threading.Thread(target=multiply_elements,args=(A,B,i,j))
            threads.append(thread)
            thread.start()
    
    for thread in threads:
        thread.join()

    # print resultant matrix
    for row in result:
        print(row)
main()