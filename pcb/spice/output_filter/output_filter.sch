v 20100214 2
C 40000 40000 0 0 0 title-B.sym
C 43600 45600 1 0 0 coil-2.sym
{
T 43800 46100 5 10 0 0 0 0 1
device=COIL
T 43800 45900 5 10 1 1 0 0 1
refdes=L2
T 43800 46300 5 10 0 0 0 0 1
symversion=0.1
T 43800 45400 5 10 1 1 0 0 1
value=6.2n
}
C 45800 45600 1 0 0 coil-2.sym
{
T 46000 46100 5 10 0 0 0 0 1
device=COIL
T 46000 45900 5 10 1 1 0 0 1
refdes=L3
T 46000 46300 5 10 0 0 0 0 1
symversion=0.1
T 45800 45600 5 10 1 1 0 0 1
value=22n
}
C 47000 45600 1 0 0 coil-2.sym
{
T 47200 46100 5 10 0 0 0 0 1
device=COIL
T 47200 45900 5 10 1 1 0 0 1
refdes=L4
T 47200 46300 5 10 0 0 0 0 1
symversion=0.1
T 47000 45600 5 10 1 1 0 0 1
value=22n
}
C 45900 44700 1 90 0 capacitor-1.sym
{
T 45200 44900 5 10 0 0 90 0 1
device=CAPACITOR
T 45400 44900 5 10 1 1 90 0 1
refdes=C2
T 45000 44900 5 10 0 0 90 0 1
symversion=0.1
T 45900 44700 5 10 1 1 0 0 1
value=3.3p
}
C 47100 44700 1 90 0 capacitor-1.sym
{
T 46400 44900 5 10 0 0 90 0 1
device=CAPACITOR
T 46600 44900 5 10 1 1 90 0 1
refdes=C3
T 46200 44900 5 10 0 0 90 0 1
symversion=0.1
T 47100 44700 5 10 1 1 0 0 1
value=8.2p
}
C 48300 44700 1 90 0 capacitor-1.sym
{
T 47600 44900 5 10 0 0 90 0 1
device=CAPACITOR
T 47800 44900 5 10 1 1 90 0 1
refdes=C4
T 47400 44900 5 10 0 0 90 0 1
symversion=0.1
T 48300 44700 5 10 1 1 0 0 1
value=3.3p
}
C 44700 45500 1 0 0 capacitor-1.sym
{
T 44900 46200 5 10 0 0 0 0 1
device=CAPACITOR
T 44900 46000 5 10 1 1 0 0 1
refdes=C1
T 44900 46400 5 10 0 0 0 0 1
symversion=0.1
T 44700 45500 5 10 1 1 0 0 1
value=470p
}
C 43600 45800 1 90 0 coil-2.sym
{
T 43100 46000 5 10 0 0 90 0 1
device=COIL
T 43300 46000 5 10 1 1 90 0 1
refdes=L1
T 42900 46000 5 10 0 0 90 0 1
symversion=0.1
T 43800 46000 5 10 1 1 90 0 1
value=27n
}
N 42500 45700 43600 45700 4
{
T 43000 45500 5 10 1 1 0 0 1
netname=in
}
N 43500 45700 43500 45800 4
N 44600 45700 44700 45700 4
N 45600 45700 45800 45700 4
N 45700 45600 45700 45700 4
N 46800 45700 47000 45700 4
N 46900 45600 46900 45700 4
N 48000 45700 48500 45700 4
{
T 48200 45500 5 10 1 1 0 0 1
netname=out
}
N 48100 45700 48100 45600 4
N 45700 44700 48100 44700 4
C 46800 44300 1 0 0 gnd-1.sym
N 46900 44700 46900 44600 4
C 41900 46300 1 0 0 vdc-1.sym
{
T 42600 46950 5 10 1 1 0 0 1
refdes=V1
T 42600 47150 5 10 0 0 0 0 1
device=VOLTAGE_SOURCE
T 42600 47350 5 10 0 0 0 0 1
footprint=none
T 42600 46750 5 10 1 1 0 0 1
value=DC 3.3V
}
C 42200 44500 1 0 0 vac-1.sym
{
T 42900 45150 5 10 1 1 0 0 1
refdes=V2
T 42900 45350 5 10 0 0 0 0 1
device=vac
T 42900 45550 5 10 0 0 0 0 1
footprint=none
T 42900 44950 5 10 1 1 0 0 1
value=dc 0 ac 1
}
C 42100 45900 1 0 0 gnd-1.sym
N 42500 44300 42500 44500 4
N 42200 46300 42200 46200 4
N 42200 47500 43500 47500 4
N 43500 47500 43500 46800 4
C 42400 44000 1 0 0 gnd-1.sym
