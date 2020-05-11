
"""
Plusieurs facteurs a prendre en compte :
	- La distance a effectuer;
	- La capacite du reservoir de la voiture;
	- La consommation par kilometres de la voiture;
	- Le prix en dollars pour remplir la voiture;
	- Le nombre de station (inferieur a 51) sur la route;
	- La distance de la ville d'origine a la station service
	- Le prix du gasoil vendu a la station
	- Le chauffeur prend un snack (2.00) a chaque station.

Resultat :
	Avoir le prix minimum de nourriture que le chauffeur aura pris et le prix du gasoil mis
"""


import time
INF = 1 << 31

def solving_problem(par):
    def execute(curDist, curGas, curCost):
        '''
        execute to get the results
        curDist - dist from origin
        curCost - cash spent so far
        return true if destination is dest_reached
        '''
        if curCost > minCost[0] or curGas < 0.0:
            return False

        if distFinal - curDist <= curGas * mpg:
            minCost[0] = min(minCost[0], curCost)
            return True

        dest_reached = False
        for s in stations:
            if s[0] <= curDist or s[0] - curDist > curGas * mpg:
                continue
            lastGasStation = (s[0] - curDist) / mpg
            step_road = execute(s[0], curGas - lastGasStation, curCost)
            if not step_road or curGas - lastGasStation <= capacity / 2.0:
                second_step_road = execute(s[0], capacity, curCost + round((
                    capacity - (curGas - lastGasStation)) * s[1]) + 200)
            if step_road or second_step_road:
                dest_reached = True
        return dest_reached

    distFinal, capacity, mpg, gasPrice, N, stations = par
    stations.sort()
    minCost = [INF]
    execute(0.0, capacity, int(gasPrice))
    return '%.2f' % (minCost[0] / 100.0)


class Budget_Solver:

    def getInput(self):
        self.numberTests = 0
        self.input = []
        while True:
            dist = float(self.fInput.readline())
            if dist < 0:
                break
            self.numberTests += 1
            capacity, mpg, gasPrice, N = map(
                float, self.fInput.readline().split())
            gasPrice *= 100
            N = int(N)
            stations = []
            for i in range(N):
                stations.append(map(float, self.fInput.readline().split()))

            self.input.append(
                (dist, capacity, mpg, gasPrice, N, stations))

    def __init__(self):
        self.fInput = open('test.txt')
        self.fOutput = open('output.txt', 'w')
        self.results = []
    def sequential_work(self):
        self.getInput()
        millis1 = int(round(time.time() * 1000))
        for i in self.input:
            self.results.append(solving_problem(i))
        millis2 = int(round(time.time() * 1000))
        print("Time in milliseconds: %d " % (millis2 - millis1))
        self.makeOutput()

    def makeOutput(self):
        for test in range(self.numberTests):
            self.fOutput.write("%s\n" % self.results[test])
        self.fInput.close()
        self.fOutput.close()

if __name__ == '__main__':
    solver = Budget_Solver()
    solver.sequential_work()