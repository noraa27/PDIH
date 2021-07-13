library(tuneR)
library(seewave)
#Cargamos los archivos
perro <- readWave('C:/Users/noraa/Desktop/P5/perro.wav')
perro
gato <- readMP3('C:/Users/noraa/Desktop/P5/gato.mp3')
gato

#Representamos gráficamente las frecuencias de las señales de los archivos recién extraídos
plot( extractWave(perro, from = 1, to = 2914304) )
plot( extractWave(gato, from = 1, to = 1724544) )

#Obtenemos los valores de las variables
str(gato)
str(perro)

#Sumamos las freecuencias de los archivos leídos anteriormente y representamos el resultado de dicha suma
s <- pastew(perro, gato, output="Wave")
s
plot( extractWave(s, from = 1, to=4638848) )

#Asignamos el valor de la frecuencia a 44100Hz
f <-  44100

#Filtramos
sndF <- bwfilter(s, f=f, channel=1, n=1, from=10000, to=20000, bandpass=TRUE, listen = FALSE, output = "Wave")

#Guardamos en el fichero mezcla.wav
writeWave(sndF, file.path('C:/Users/noraa/Desktop/P5/mezcla.wav') )

#Cargamos el archivo recién creado
mezcla <-  readWave('C:/Users/noraa/Desktop/P5/mezcla.wav')

#Obtenemos los valores de la variable mezcla
str(mezcla)

#Aplicamos eco al archivo
mezclaECO <- echo(mezcla,f=22050,amp=c(0.8,0.4,0.2),delay=c(1,2,3),output="Wave")

#Damos la vuelta al sonido
reverse <- revw(mezcla, output="Wave")

#Guardamos en el fichero reverse.wav
writeWave(reverse, file.path("C:/Users/noraa/Desktop/P5/reverse.wav") )











