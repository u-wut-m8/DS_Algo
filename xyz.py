''' Read input from STDIN. Print your output to STDOUT '''
    #Use input() to read input from STDIN and use print to write your output to STDOUT

def main():
 # Write code here
    d = {'A':'T', 'T':'A', 'C':'G', 'G':'C'}
    s = input()
    s = s[::-1]
    for val in s:
        print(d[val], end="")
        
main()