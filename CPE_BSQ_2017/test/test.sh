#!/bin/sh
## EPITECH PROJECT, 2017
## voici mes tests > sources mouli map test
## File description:
## tests automatisés
##

# test 1

echo "test 1 : Map 34_137_empty"
./bsq mouli_maps/intermediate_map_34_137_empty > test_1
diff test_1 mouli_maps_solved/intermediate_map_34_137_empty

#test 2

echo "test 2 : Map 34_137_filled"
./bsq mouli_maps/intermediate_map_34_137_filled > test_2
diff test_2 mouli_maps_solved/intermediate_map_34_137_filled

#test 3

echo "test 3 : Map 34_137_with_obstacles_25pc"
./bsq mouli_maps/intermediate_map_34_137_with_obstacles_25pc > test_3
diff test_3 mouli_maps_solved/intermediate_map_34_137_with_obstacles_25pc

#test 4

echo "test 4 : Map 34_137_with_obstacles_50pc"
./bsq mouli_maps/intermediate_map_34_137_with_obstacles_50pc > test_4
diff test_4 mouli_maps_solved/intermediate_map_34_137_with_obstacles_50pc

#test 5

echo "test 5 : Map 34_137_with_obstacles_75pc"
./bsq mouli_maps/intermediate_map_34_137_with_obstacles_75pc > test_5
diff test_5 mouli_maps_solved/intermediate_map_34_137_with_obstacles_75pc

#test 6

echo "test 6 : Map 97_21_empty"
./bsq mouli_maps/intermediate_map_97_21_empty > test_6
diff test_6 mouli_maps_solved/intermediate_map_97_21_empty

#test 7

echo "test 7 : Map 97_21_filled"
./bsq mouli_maps/intermediate_map_97_21_filled > test_7
diff test_7 mouli_maps_solved/intermediate_map_97_21_filled

#test 8

echo "test 8 : Map 97_21_with_obstacles_25pc"
./bsq mouli_maps/intermediate_map_97_21_with_obstacles_25pc > test_8
diff test_8 mouli_maps_solved/intermediate_map_97_21_with_obstacles_25pc

#test 9

echo "test 9 : Map 97_21_with_obstacles_50pc"
./bsq mouli_maps/intermediate_map_97_21_with_obstacles_50pc > test_9
diff test_9 mouli_maps_solved/intermediate_map_97_21_with_obstacles_50pc

#test 10

echo "test 10 : Map 97_21_with_obstacles_75pc"
./bsq mouli_maps/intermediate_map_97_21_with_obstacles_75pc > test_10
diff test_10 mouli_maps_solved/intermediate_map_97_21_with_obstacles_75pc

#test 11

echo "test 11 : Map 100_100"
./bsq mouli_maps/intermediate_map_100_100 > test_11
diff test_11 mouli_maps_solved/intermediate_map_100_100

#test 12

echo "test 12 : Map 187_187_empty"
./bsq mouli_maps/intermediate_map_187_187_empty > test_12
diff test_12 mouli_maps_solved/intermediate_map_187_187_empty

#test 13

echo "test 13 : Map 187_187_filled"
./bsq mouli_maps/intermediate_map_187_187_filled > test_13
diff test_13 mouli_maps_solved/intermediate_map_187_187_filled

#test 14

echo "test 14 : Map 187_187_with_obstacles_25pc"
./bsq mouli_maps/intermediate_map_187_187_with_obstacles_25pc > test_14
diff test_14 mouli_maps_solved/intermediate_map_187_187_with_obstacles_25pc


#test 15

echo "test 15 : Map 187_187_with_obstacles_50pc"
./bsq mouli_maps/intermediate_map_187_187_with_obstacles_50pc > test_15
diff test_15 mouli_maps_solved/intermediate_map_187_187_with_obstacles_50pc

#test 16

echo "test 16 : Map 187_187_with_obstacles_75pc"
./bsq mouli_maps/intermediate_map_187_187_with_obstacles_75pc > test_16
diff test_16 mouli_maps_solved/intermediate_map_187_187_with_obstacles_75pc

#test 17

echo "test 17 : Map 200_200"
./bsq mouli_maps/intermediate_map_200_200 > test_17
diff test_17 mouli_maps_solved/intermediate_map_200_200

#test 18

echo "test 18 : Map 500_500"
./bsq mouli_maps/intermediate_map_500_500 > test_18
diff test_18 mouli_maps_solved/intermediate_map_500_500

#test 19

echo "test 19 : Map 500_500_2"
./bsq mouli_maps/intermediate_map_500_500_2 > test_19
diff test_19 mouli_maps_solved/intermediate_map_500_500_2

#test 20

echo "test 20 : Map 500_500_3"
./bsq mouli_maps/intermediate_map_500_500_3 > test_20
diff test_20 mouli_maps_solved/intermediate_map_500_500_3

#test 21

echo "test 21 : Map 1000_1000"
./bsq mouli_maps/intermediate_map_1000_1000 > test_21
diff test_21 mouli_maps_solved/intermediate_map_1000_1000

#test 22

echo "test 22 : Map 1000_1000_2"
./bsq mouli_maps/intermediate_map_1000_1000_2 > test_22
diff test_22 mouli_maps_solved/intermediate_map_1000_1000_2

#test 23

echo "test 23 : Map 2000_2000"
./bsq mouli_maps/intermediate_map_2000_2000 > test_23
diff test_23 mouli_maps_solved/intermediate_map_2000_2000

#test 24

echo "test 24 : Map 5000_5000"
./bsq mouli_maps/intermediate_map_5000_5000 > test_24
diff test_24 mouli_maps_solved/intermediate_map_5000_5000

#test 25

echo "test 25 : Map 10000_10000"
./bsq mouli_maps/intermediate_map_10000_10000 > test_25
diff test_25 mouli_maps_solved/intermediate_map_10000_10000

#test 26

echo "test 26 : Map empty_corners"
./bsq mouli_maps/intermediate_map_empty_corners > test_26
diff test_26 mouli_maps_solved/intermediate_map_empty_corners

#test 27

echo "test 27 : Map filled_corners"
./bsq mouli_maps/intermediate_map_filled_corners > test_27
diff test_27 mouli_maps_solved/intermediate_map_filled_corners

#test 28

echo "test 28 : Map one_column_with_obstacles_25pc"
./bsq mouli_maps/intermediate_map_one_column_with_obstacles_25pc > test_28
diff test_28 mouli_maps_solved/intermediate_map_one_column_with_obstacles_25pc

#test 29

echo "test 29 : Map one_column_with_obstacles_50pc"
./bsq mouli_maps/intermediate_map_one_column_with_obstacles_50pc > test_29
diff test_29 mouli_maps_solved/intermediate_map_one_column_with_obstacles_50pc

#test 30

echo "test 30 : Map one_column_with_obstacles_75pc"
./bsq mouli_maps/intermediate_map_one_column_with_obstacles_75pc > test_30
diff test_30 mouli_maps_solved/intermediate_map_one_column_with_obstacles_75pc

#test 31

echo "test 31 : Map one_empty_box"
./bsq mouli_maps/intermediate_map_one_empty_box > test_31
diff test_31 mouli_maps_solved/intermediate_map_one_empty_box

#test 32

echo "test 32 : Map one_empty_column"
./bsq mouli_maps/intermediate_map_one_empty_column > test_32
diff test_32 mouli_maps_solved/intermediate_map_one_empty_column

#test 33

echo "test 33 : Map one_empty_line"
./bsq mouli_maps/intermediate_map_one_empty_line > test_33
diff test_33 mouli_maps_solved/intermediate_map_one_empty_line

#test 34

echo "test 34 : Map one_filled_box"
./bsq mouli_maps/intermediate_map_one_filled_box > test_34
diff test_34 mouli_maps_solved/intermediate_map_one_filled_box

#test 35

echo "test 35 : Map one_filled_column"
./bsq mouli_maps/intermediate_map_one_filled_column > test_35
diff test_35 mouli_maps_solved/intermediate_map_one_filled_column

#test 36

echo "test 36 : Map one_filled_line"
./bsq mouli_maps/intermediate_map_one_filled_line > test_36
diff test_36 mouli_maps_solved/intermediate_map_one_filled_line

#test 37

echo "test 37 : Map one_line_with_obstacles_25pc"
./bsq mouli_maps/intermediate_map_one_line_with_obstacles_25pc > test_37
diff test_37 mouli_maps_solved/intermediate_map_one_line_with_obstacles_25pc

#test 38

echo "test 38 : Map one_line_with_obstacles_50pc"
./bsq mouli_maps/intermediate_map_one_line_with_obstacles_50pc > test_38
diff test_38 mouli_maps_solved/intermediate_map_one_line_with_obstacles_50pc

#test 39

echo "test 39 : Map one_line_with_obstacles_75pc"
./bsq mouli_maps/intermediate_map_one_line_with_obstacles_75pc > test_39
diff test_39 mouli_maps_solved/intermediate_map_one_line_with_obstacles_75pc

rm test_*
