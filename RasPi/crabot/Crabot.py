#!/usr/bin/env python3

import serial
import functions
import functions_macro

ser = serial.Serial("/dev/ttyAMA0",57600)

functions.reset_pic()
functions.init_ax(ser)
while 1:

	# Attente du start
	print "waiting for start"
	answer = functions.get_ans(ser)
	while answer != "$STRT;":
		 answer = functions.get_ans(ser)
		 print answer

	# demande de l'equipe
	team = 0
	while team==0 :
		team = functions.ask_team(ser)

	configuration = -1
	while configuration==-1:
		configuration = functions.ask_conf(ser)
	
	### SCRIPT DE RECALAGE ###
	if configuration == 0: 			
		functions_macro.Script_Recalage(ser,team)
	
	### SCRIPTS DE MATCH ###
	elif configuration < 6:			
		functions_macro.Prise_Petit_Tas_De_Sable(ser,team,configuration)
		functions_macro.Recaler_Coquillage(ser,team,configuration)
		functions_macro.Fermeture_Portes(ser,team)
		functions_macro.Prise_Grand_Tas_De_Sable(ser,team,configuration)
		if configuration != 1:
			functions_macro.Prise_Poissons(ser,team)
			functions_macro.Prise_Coquillages_1(ser,team,configuration)
			functions_macro.Prise_Coquillages_2(ser,team,configuration)
		else :
			functions_macro.Prise_Coquillages_1(ser,team,configuration)
			functions_macro.Prise_Poissons(ser,team)
	
	### SCRIPT D'HOMOLOGATION ###
	elif configuration == 6:		
		functions_macro.Homologation(ser,team)

ser.close()

