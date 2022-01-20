import os
import threading
import matplotlib.pyplot as plt

from AlgoritmosExperimentos.caminhos import caminhos


class Grafico:
    def __init__(self, karatsuba , direto, id):
        self.karatsuba = open(karatsuba,'r')
        self.direto = open(direto,'r')
        self.id = id

        self.k = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
        self.temp_ka = []
        self.temp_dir = []

        self.le_aquivo()
        self.monta_grafico()

    def le_aquivo(self):

        self.entrada = self.karatsuba.readlines()
        self.entrada2 = self.direto.readlines()

        for i in range (0,len(self.entrada)):
            info = self.entrada[i].split("/")

            y = info[1]
            self.temp_ka.append(float(y[:-1]))

        for i in range(0, len(self.entrada2)):
            info = self.entrada2[i].split("/")

            y = info[1]

            self.temp_dir.append(float(y[:-1]))



    def monta_grafico(self):
        plt.plot(self.k, self.temp_dir, C='blue',marker='o',fillstyle="full", label= "Multiplicação direta")
        plt.plot(self.k, self.temp_ka, C='red', marker='o', fillstyle="full", label = "Método de Karatsuba")
        plt.legend()
        plt.title("Comparação do método direto e de Karatsuba",fontsize="14")
        plt.xlabel("k", fontsize="14")
        plt.ylabel("tempo", fontsize="14")


        plt.savefig('gráfico' +str(self.id))
        plt.close()


    def limpa_grafo(self):
        self.temp_ka = []
        self.temp_dir = []
        self.k = []

def cria_objeto(k,d,id):
    grafico = Grafico(k, d,id)

def main ():
    grafico =1
    for a in range (0,6):
        cria_objeto(caminhos[a],caminhos[a+6],grafico)
        grafico +=1

main()