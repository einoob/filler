# Filler: Battle of the algorithms.
This project is about creating a bot that plays the game called filler. The goal of the game is to collect as many points as possible by placing the highest number of pieces on the the game board. At every turn a Ruby-executable gives a randomly shaped piece that must be placed on the board. The winner is the one with most pieces placed on the board.

My algorithm goes to the furthermost corner from it's starting point. Once the top or the bottom of the map is reached or contact with the enemy is apparent, it start's to block the enemy's path by placing pieces near the enemy. Samples of matches between my algorithm (orange) and a few given algorithms (blue) below:

## 17x15 Board
<img width="1546" alt="map01" src=https://github.com/einoob/filler/blob/master/samples/map00.gif>

## 40x24 Board
<img width="1546" alt="map01" src=https://github.com/einoob/filler/blob/master/samples/map01hcao.gif>

## 99x100 Board
<img width="1546" alt="map01" src=https://github.com/einoob/filler/blob/master/samples/map02superjeannot.gif>
