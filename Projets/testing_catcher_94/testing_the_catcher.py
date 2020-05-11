import sys

def defense_System(missile):
    N = len(missile)
    longest = [0] * N
    longest[0] = 1
    for number_missile in range(1, N):
        maxIntercept = 1
        for j in range(number_missile):
            #cmp each value in list and class by being superior
            if missile[number_missile] <= missile[j] and longest[j] + 1 > maxIntercept:
                maxIntercept = longest[j] + 1
        longest[number_missile] = maxIntercept
        #return max interception
    return max(longest)


if __name__ == '__main__':
    sys.stdin = open('test.txt', 'r')
    missile = []
    while True:
        #adding value in list missile
        n = int(input())
        if n == -1:
            print('maximum possible interceptions: %d' % defense_System(missile))
            missile = []
            n1 = int(input())
            if n1 == -1:
                break
            else:
                missile.append(n1)
        else:
            missile.append(n)
