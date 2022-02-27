# Thanos-Endgame
Command line based RPG implementing object oriented design principles and polymorphism. 

The main premise of the game is you're Thanos trying to collect the infinity Gems from 5 of the Avengers located within the Avenger's Headquarters. 

The starting gameboard is below and to play you move to each room by selecting one of the coresponding menu options. Movement is restricted to only allow movement to rooms connnected to the current room you are in.

![output](https://raw.githubusercontent.com/keenonhh/Thanos-Endgame/master/GameBoard.PNG)

When you enter a room you automatically fight the Avenger located within as long as they haven't already been defeated in order to take the Infinity Gem that they are protecting. Each Avenger has a different power level determined by random number generation. Thanos has a base power level that increases with each Infinity Gem collected making it easier to defeat the more powerful Avengers. 

The Game is over once you have collected all 5 Inifinity Gems, ran out of time(steps), or your health reaches 0 from being defeated in battle too many times.  
