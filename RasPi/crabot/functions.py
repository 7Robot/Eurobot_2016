#!/usr/bin/env python3

import serial
from time import sleep
import RPi.GPIO as GPIO

Sicks=0

def get_ans(ser):
	global Sicks
	s=ser.read(1)
	chaine=""
	while s!=';' :
		chaine += s
		s=ser.read(1)
	chaine += s
	#if chaine=="$CNCL;":
		### REBOOT PI
	if chaine=="$DSI0;":
		Sicks+=1
	elif chaine=="$DSI1;":
		Sicks+=2
	elif chaine=="$DSI2;":
		Sicks+=4
	elif chaine=="$DSI3;":
		Sicks+=8
	elif chaine=="$DULS;":
		Sicks+=16
	elif chaine=="$RSI0;":
		Sicks-=1
	elif chaine=="$RSI1;":
		Sicks-=2
	elif chaine=="$RSI2;":
		Sicks-=4
	elif chaine=="$RSI3;":
		Sicks-=8
	elif chaine=="$RULS;":
		Sicks-=16
	print ("    "+chaine)
	sleep(0.1)
	return chaine

def reset_pic():
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(17, GPIO.OUT)
	GPIO.output(17, True)
	sleep(2)
	GPIO.output(17, False)
	sleep(6) # temps d'init du pic

def enable_sicks(ser,sicks):
	### valeur en hexa de 0 a F.
	#   0 tous desactives F tous actives
	#   9 desactive les sicks avant
	### 6 desactive les sicks arriere
	command = "$ENSI,"+sicks+";"
	ser.write(command)
	print(command)

def move_pos(ser,x,y):
	angle="0"
	command = "$MOVE,"+str(x)+","+str(y)+","+angle+";"
	ser.write(command)
	print (command) #affiche dans la console

def move_push(ser,x,y,d):
	angle = "0"
	command = "$PUSH,"+str(x)+","+str(y)+","+angle+","+str(d)+";"
	ser.write(command)
	print(command)

def set_x(ser,x):
	command ="$SETX,"+str(x)+";"
	ser.write(command)
	print ("MAJ de coordonnee x="+str(x))

def set_y(ser,y):
        command ="$SETY,"+str(y)+";"
        ser.write(command)
        print ("MAJ de coordonnee y="+str(y))

def set_t(ser,angle):
	angle = 6.28318*angle/360	#conversions degres a radians par seconde
        command ="$SETA,"+str(angle)+";"
        ser.write(command)
        print ("MAJ de coordonnee angle="+str(angle))

def set_speed(ser,max):
	command ="$VMAX,"+str(max)+";"
	ser.write(command)
	print ("Changement de vmax :"+command)

def set_speed_ang(ser,max):
        command ="$VTMA,"+str(max)+";"
        ser.write(command)
        print ("Changement de vt_max :"+command)

def set_acc(ser,al,at,a):
	command ="$AMAX,"+str(al)+","+str(at)+","+str(a)+";"
	ser.write(command)
	print ("Chamgement d'accelerations max : "+str(al)+" ,"+str(at)+" ,"+str(a)+";")

def move_speed(ser,v,vt):
	vt = 6.28318*vt/360 #conversion degres radians
	command ="$SPED,"+str(v)+","+str(vt)+";"
	ser.write(command)
	print (command) #affiche dans la console

def rotate(ser,angle):
	angle = 6.28318*angle/360	#conversions degres a radians par seconde
	command = "$ANGL,"+str(angle)+";"
	ser.write(command)
	print (command) #affiche dans la console

def motion_free(ser):
	command = "$FREE;"
	print command
	ser.write(command)

def init_ax(ser):
	command = "$AXIN;"
	ser.write(command)
	print (command)

def ask_team(ser):
	command = "$TEAM;"
	ser.write(command)
	print (command)
	s=get_ans(ser)
	if s=="$VIOL;":
		team=1
	elif s=="$VERT;":
		team=-1
	else :
		team = 0
	return team

def ask_conf(ser):
	command = "$CONF;"
	ser.write(command)
	print (command)
	s = get_ans(ser)
	if s=="$CON0;":
		configuration = 0
        elif s=="$CON1;":
                configuration = 1
	elif s=="$CON2;":
		configuration = 2
	elif s=="$CON3;":
		configuration = 3
	elif s=="$CON4;":
		configuration = 4
	elif s=="$CON5;":
		configuration = 5
	elif s=="$CON6;":
                configuration = 6
	elif s=="$CON7;":
                configuration = 7
	else :
		configuration = -1
	return configuration
	
	
#listes des actions propres au robot

def deploy_fish_av(ser): # deploie les bras pour la peche a l avant
	command = "$DFAV;"
	print command
	ser.write(command)

def deploy_fish_ar(ser): # deploie les bras pour la peche a l arriere
	command = "$DFAR;"
	print command
	ser.write(command)

def deploy_fish(ser): # deploie les bras pour la peche
        command = "$DFIS;"
        print command
        ser.write(command)

def moveup_fish_av(ser): # souleve un peu les bras avant pour emmener les poissons dans le filet
	command = "$UPAV;"
	print command
	ser.write(command)

def moveup_fish_ar(ser): # souleve un peu les bras arriere pour emmener les poissons dans le filet
	command = "$UPAR;"
	print command
	ser.write(command)

def rlz_fish_av(ser): # lache les poissons dans le filet et range les bras avant 
	command = "$RFAV;"
	print command
	ser.write(command)

def rlz_fish_ar(ser): # lache les poissons dans le filet et range les bras arriere 
	command = "$RFAR;"
	print command
	ser.write(command)

def rlz_fish(ser): # lache les poissons dans le filet et range les bras arriere
        command = "$RFIS;"
        print command
        ser.write(command)


def open_bras(ser): # ouvre les petit bras du robot pour prendre blocs de sable
	command = "$OPNB;"
	print command
	ser.write(command)

def open_full_bras(ser): #ouvre les bras en entier pour pouvoir pousser les portes
	command = "$OPFB;"
	print command
	ser.write(command)

def close_bras(ser): # referme les bras
	command = "$CLOB;"
	print command
	ser.write(command)

def catch(ser): # referme un peu les bras pour serrer les blocs
	command = "$CATB;"
	print command
	ser.write(command)

def funny_action(ser): # demarre la funny action
	command = "$FUNA;"
	print command
	ser.write(command)
