import os
import threading
import matplotlib.pyplot as plt


class Grafico:
    def __init__(self, karatsuba , direto):
        self.karatsuba = open(karatsuba,'r')
        self.direto = open(direto,'r')

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

        plt.show()
def cria_objeto(k,d):
    grafico = Grafico(k, d)

def main ():
    caminhos = []

    caminhok1 = os.path.abspath('EsperimentosCoefIguais/karatsuba1')
    caminhok2 = os.path.abspath('EsperimentosCoefIguais/karatsuba2')
    caminhok3 = os.path.abspath('EsperimentosCoefIguais/karatsuba3')
    caminhok4 = os.path.abspath('EsperimentosCoefIguais/karatsuba4')

    caminhod1 = os.path.abspath('EsperimentosCoefIguais/mult_direta1')
    caminhod2 = os.path.abspath('EsperimentosCoefIguais/mult_direta2')
    caminhod3 = os.path.abspath('EsperimentosCoefIguais/mult_direta3')
    caminhod4 = os.path.abspath('EsperimentosCoefIguais/mult_direta4')

    caminhos.append(caminhok1)
    caminhos.append(caminhok2)
    caminhos.append(caminhok3)
    caminhos.append(caminhok4)
    caminhos.append(caminhod1)
    caminhos.append(caminhod2)
    caminhos.append(caminhod3)
    caminhos.append(caminhod4)

    threading.Thread(target=cria_objeto(caminhos[0],caminhos[4])).start()
    threading.Thread(target=cria_objeto(caminhos[1], caminhos[5])).start()
    threading.Thread(target=cria_objeto(caminhos[2], caminhos[6])).start()

main()