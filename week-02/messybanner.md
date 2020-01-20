# Messy Banner

In the process of adding new courses, due to the archaic interface of self-service, a large amount of invalid data was added to MUNs banner system!

It'd be too tricky to manually go through it all by hand, so you have been tasked to clean up this data.

Telling the difference between garbled and real data requires knowing what _good_ data looks like, and since room numbers follow a specific pattern, you filter the data you have by where they should be found.

The following are valid rooms, as banner displays them [here](https://www5.mun.ca/admit/hwswsltb.P_CourseSearch?p_term=201902&p_levl=01*04).

```
A  1046
ED 3022
IIC2001
ED 2018A
```

The following are _invalid_ rooms:

```
a  1026
   1234
absakdjm
ED 3022_
 ICC2001
C 2001
```

Since you want your implmentation to be generic enough that it doesn't have to be changed in the future, you shouldn't validate that a building actually exists.

Also, since online courses don't have physical rooms, you also consider no data to be valid data.

## Input

Each line is the piece of data 8 characters in length, which can be either valid or invalid.

## Output

Each line of the output matches each line of the input; `Y` if the room is valid, `N` if it is not.

## Sample:

**Input:**

```
ED 3022
a  1026
IIC2001
ED 2018A
absakdjm
A  1046f
EN 2036
SN 1234_
```

**Output:**

```
Y
N
Y
Y
N
N
Y
N
```

