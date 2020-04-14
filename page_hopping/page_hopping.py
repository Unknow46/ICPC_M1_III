import sys

LIMIT = 101

if __name__ == '__main__':
    sys.stdin = open('test.txt')

    while True:
        ligne = map(int, raw_input().strip().split())
        if ligne[0] == 0 and ligne[1] == 0:
            break
        nodes = list(set(ligne))
        nodes.sort()
        del nodes[0]
        nNodes = len(nodes)

        graph = nNodes*[nNodes*[0]]

        n = len(ligne) / 2 - 1
        for i in range(n):
            x = nodes.index(ligne[i * 2])
            y = nodes.index(ligne[i * 2 + 1])
            graph[x][y] = 1
            graph[x][x] = 0

        for k in range(nNodes):
            for i in range(nNodes):
                for j in range(nNodes):
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])