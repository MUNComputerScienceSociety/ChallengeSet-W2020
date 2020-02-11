# Intro

Ever seen one of my nonsensical challenge set solutions and wondered what went into making such a thing? You've come to the right place! In this document I'll be writing up the process of creating my solution for `iBoard`, from week 4.

# Rule Overview

In case you are unaware of this, each week I solve the week's problems with a new rule *in addition to all the rules from previous weeks*. As of the week in which this documentation is for, the following rules exist:

## Each file must be a single statement

My solution must comprise of a single valid python statement. As Python allows multiple statements (normal lines of code) on one line via the use of semicolons, this rule specifically calls for statements rather than lines in order to prevent me from simply abusing semicolons to create a single-line solution.

### Valid

```python
print("\n".join(map(str, range(5))))
```

### Invalid

```python
for i in range(5):
    print(i)
```

## Variable names must be comprised entirely of underscores

In order to further obfuscate my solutions, I have restricted the character set I am permitted to use for variable names. Normally, Python supports characters a through z (both upper and lower case), underscores, and numbers anywhere other than in the first character. In order for maximum unreadability, underscores were chosen as the subset of the default alphabet that would remain permitted.

### Valid

```python
_ = ["a", "b", "c"]
```

### Invalid

```python
identifiers = ["a", "b", "c"]
```

## No importing of any files outside the standard library

In order to prevent bypassing of the first rule (as well as to permit the testing of my solutions on Kattis), importing of any files or libraries outside of the standard library is not permitted. If the functions I want to use don't exist in the standard library, I'll need to implement them *within* my solution.

### Valid

```python
def double_number(number):
    return number * 2

print(double_number(2))
```

### Invalid

```python
from fake_module import double_number

print(double_number(2))
```

## No use of string literals

Once again, in order to further obfuscate my solutions, I'm forbidden from using string literals within my code. *Strings themselves* are still permitted, but I'll need to use other methods to construct them.

### Valid

```python
print(
    str().join(
        map(
            chr,
            [
                72,
                101,
                108,
                108,
                111,
                32,
                119,
                111,
                114,
                108,
                100
            ]
        )
    )
)
```

### Invalid

```python
print("Hello world")
```

## No usage of `chr`

`chr` is Python's built-in character code to string conversion function. By combining it with map and join, plus using something like CyberChef to quickly convert a string to an array of character codes, we can easily get around the no string literals rule. However, because this code needs to be a nightmare in every way possible and that's too easy, I'm forbidden from using it and I must find other means to construct my strings.

[CyberChef](https://gchq.github.io/CyberChef/)

### Valid

```python
print(
    str.__name__ +
    int.__name__[:-1] +
    globals.__name__[0]
)
```

### Invalid

```python
print(
    str().join(
        map(
            chr,
            [
                115,
                116,
                114,
                105,
                110,
                103
            ]
        )
    )
)
```

## No use of numeric literals

At this point, numbers are the main immediate things that stand out from our sea of underscores and function calls. The solution? Let's ban them entirely. Once again, like the string literal rule the use of numbers is still permitted (math would be a bit difficult without them), but we'll need to find new ways of acquiring them.

### Valid

```python
zero, one, two = map(
    len,
    [
        [],
        [...],
        [..., ...]
    ]
)

print(two * (zero - one))
```

### Invalid

```python
print(2 * -1)
```

# Building Blocks - The Basics

Now that the rules are out of the way, we now have a bunch of restrictions placed on how we can go about solving our problems. However, these rules were purposefully chosen because there *are* ways to get around them, by combining one or more building blocks. Before I get into the advanced abuse of Python's features and syntax, I'll get the simpler building blocks out of the way. These are the ones that you might have already seen, or have even used in your own code at some point.

## List Comprehensions

Given that a for loop comprises multiple statements, we're unable to use them. Thankfully, Python provides a wonderful method of getting around this known as *list comprehensions*. They are a tremendously useful part of Python's syntax that effectively allow you to build a list from executing a very simple for loop. We'll be using them to replace all usages of for loops in our code.

### Before

```python
items = []
for i in range(10):
    items.append(i)
print(items)
```

### After

```python
items = [i for i in range(10)]
print(items)
```

## Recursion

While less of a building block and more of a different style of programming, we'll be replacing all usages of while loops in our code with recursive programming.

### Before

```python
i = 0
while i < 10:
    i += 1

print(i)
```

### After

```python
def calculate_10(i=0):
    if i >= 10:
        return 0
    return 1 + calculate_10(i + 1)

print(calculate_10())
```

## Lambdas

Originally a concept from lambda calculus, lambdas within python are simple functions that have no name associated with them. As with the past two blocks, since normal function definitions consist of multiple statements we will be replacing them with lambdas as they are comprised of only a single statement.

### Before

```python
def double(i):
    return i * 2

print(double(2))
```

### After

```python
double = lambda i: i * 2

print(double(2))
```

# Building Blocks - Extreme Python Abuse Edition

## Y Combinators

Another concept from lambda calculus and later introduced in functional programming languages, Y combinators are a means of defining functions that refer to themselves. As lambdas won't be stored into a variable or given a name in our solutions, they have no way to call themselves. We'll be using Y combinators in order to allow our lambda functions to operate recursively.

**Additional note**: In the below example I use a modified simpler y-combinator that calls the function immediately. As we will be using this function inline, it is *generally* fine for this to be the case. There's a slightly more complicated setup that will not call immediately that you might see in my solutions occasionally, but it's rarely needed.

### Before

```python
calculate_10 = lambda i=0: (
    0
    if i >= 10
    else 1 + calculate_10(i + 1)
)
calculate_10()
```

### After

```python
(lambda f, *args: f(f, *args))(
    lambda f, i=0: (
        0
        if i >= 10
        else 1 + f(f, i + 1)
    )
)
```

## `__name__`

This one is a fairly simple one, but as it's tinkering with Python's internals I figured it'd be better to go into the Python abuse section. `__name__` is a property that exists on most (if not all) Python methods and classes that provides their name as a string. For example, `print.__name__` will simply give the string `"print"`. We'll be making extensive use of `__name__` in order to construct strings without using `chr`.

### Before

```python
print("string")
```

### After

```python
print(
    str.__name__ +
    int.__name__[:-1] +
    globals.__name__[0]
)
```

## `__import__`

Another fairly simple one like `__name__`. `__import__` is a built-in function that behaves roughly the same as using the normal import statement. As the import statement *is* a statement (I mean it's in the name), we'll be using `__import__` whenever we need to import a module.

### Before

```python
import sys
print(sys.stdin.read())
```

### After

```python
print(__import__("sys").stdin.read())
```

## `type`

This one is where we really put the extreme in extreme Python abuse. `type` is the parent class of *Python classes themselves*. Effectively, whenever you are defining a class using Python's `class` keyword, you are creating an instance of `type`. See where I'm going with this? As Python's classes are declared with multiple statements, we use `type` whenever we need to create a class, by manually calling it as you would with any normal constructor. It takes in three arguments: the name of our class, the parent classes, and a dict containing properties (variables, functions, etc.) for the class.

**Additional note**: For further understanding as to how this works, I'd really suggest you read up about metaclasses in Python (as `type` is the default metaclass)

[Understanding Python metaclasses - ... and Python objects in general](https://blog.ionelmc.ro/2015/02/09/understanding-python-metaclasses/)

### Before

```python
class MyClass:
    def __init__(self, my_val):
        self.my_val = my_val

    def get_my_val(self):
        return self.my_val
```

### After

```python
MyClass = type(
    "MyClass",
    (object,),
    {
        "__init__": (
            lambda self, my_val:
                setattr(
                    self,
                    "my_val",
                    my_val
                )
        ),
        "get_my_val": (
            lambda self:
                self.my_val
        )
    },
)
```

# Building the Solution

The first step of building the solution is solving the problem. Doesn't make sense? Believe it or not, I do not write the solutions in the final output format you see. I initially write a simple solution using normal, clean Python. Therefore, the first step of building one of my solutions is to write this simple solution. In the case of iBoard, my initial solution looked like the following:

```python
import sys

strings = sys.stdin.readlines()
for string in strings:
    codes = "".join([bin(ord(char))[2:].zfill(7) for char in string.strip()])
    ones = codes.count("1")
    zeros = codes.count("0")
    print("free" if ones % 2 == 0 and zeros % 2 == 0 else "trapped")
```

The next step is to prepare for initial one-linification. In the case of this problem, we replace the for loop with two list comprehensions and combine all the statements within it into them. We then replace the multiple print calls with a single one containing the joined results of all the inputs. This gives us the following code:

```python
import sys

strings = sys.stdin.readlines()

codes = [
    "".join([bin(ord(char))[2:].zfill(7) for char in string.strip()])
    for string in strings
]

results = [
    "free" if code.count("1") % 2 == 0 and code.count("0") % 2 == 0 else "trapped"
    for code in codes
]

print("\n".join(results))
```

Step three is to combine all the statements with the exception of the import. As we make use of each one of the declared variables only once, we can simply replace their usages with the value itself, giving us the following:

```python
import sys

print(
    "\n".join(
        [
            "free"
            if code.count("1") % 2 == 0 and code.count("0") % 2 == 0
            else "trapped"
            for code in [
                "".join([bin(ord(char))[2:].zfill(7) for char in string.strip()])
                for string in sys.stdin.readlines()
            ]
        ]
    )
)
```

Step four is to bring the `sys` import into this statement, as well as to import the `string` module, as we are going to need this shortly. We also need to rename our string var to something else to stop it from conflicting with the module. We'll wrap the whole code in a lambda so we have access to the modules multiple times, and will pass in the modules as arguments to the lambda. That results in the following:

```python
print(
    (
        lambda sys, string: "\n".join(
            [
                "free"
                if code.count("1") % 2 == 0 and code.count("0") % 2 == 0
                else "trapped"
                for code in [
                    "".join([bin(ord(char))[2:].zfill(7) for char in line.strip()])
                    for line in sys.stdin.readlines()
                ]
            ]
        )
    )(__import__("sys"), __import__("string"))
)
```

Next, we're going to get rid of the strings in the code. We replace `"sys"` with the first character of the name of `str`, the second character of the name of `type`, and the first character of the name of `str`. We replace `"string"` with the full name of `str`, everything but the last character of the name of `int`, and the first character of the name of `globals`. We can get the newline from the 2nd item of `string.whitespace` (see why I just imported it). `"free"` is the first two characters of the name of `frozenset`, followed by the first character of the name of `eval` twice. `"trapped"` is the last two characters of the name of `str`, the last two characters of the name of `map`,  the last two characters of the name of `type`, and finally the first character of the name of `dir`. The `"1"` and `"0"` can simply be replaced with the stringified values of their respective integers, resulting in the following:

```python
print(
    (
        lambda sys, string: string.whitespace[2].join(
            [
                frozenset.__name__[:2] + eval.__name__[0] + eval.__name__[0]
                if code.count(str(1)) % 2 == 0 and code.count(str(0)) % 2 == 0
                else str.__name__[1:]
                + map.__name__[1:]
                + type.__name__[2:]
                + dir.__name__[0]
                for code in [
                    str().join([bin(ord(char))[2:].zfill(7) for char in line.strip()])
                    for line in sys.stdin.readlines()
                ]
            ]
        )
    )(
        __import__(str.__name__[0] + type.__name__[1] + str.__name__[0]),
        __import__(str.__name__ + int.__name__[:-1] + globals.__name__[0]),
    )
)
```

Next step is to get rid of the integer literals. We do this by defining a new outer lambda wrapping all this which takes in the integers we need as parameters, then we pass in the result of a spread over the `map` of `len` applied to a list of lists, where the length of the list corresponds with the number we need. For further complexity, we'll use `...` as the items within the list, as well as limiting us to the base numbers of just zero, one, and two, just to make reading this even worse. This gives us the following code, which you should admire as it's the last time it'll be even remotely close to readable:

```python
print(
    (
        lambda zero, one, two: (
            lambda sys, string: string.whitespace[two].join(
                [
                    frozenset.__name__[:two] + eval.__name__[zero] + eval.__name__[zero]
                    if code.count(str(one)) % two == zero
                    and code.count(str(zero)) % two == zero
                    else str.__name__[one:]
                    + map.__name__[one:]
                    + type.__name__[two:]
                    + dir.__name__[zero]
                    for code in [
                        str().join(
                            [
                                bin(ord(char))[two:].zfill(two * two * two - one)
                                for char in line.strip()
                            ]
                        )
                        for line in sys.stdin.readlines()
                    ]
                ]
            )
        )(
            __import__(str.__name__[zero] + type.__name__[one] + str.__name__[zero]),
            __import__(
                str.__name__ + int.__name__[: zero - one] + globals.__name__[zero]
            ),
        )
    )(*map(len, [[], [...], [..., ...]]))
)
```

Next, we dive into the land of truly unreadable code. We start from the top and replace each variable name with one with varying numbers of underscores. We start with one underscore and increase by one each time, replacing all usages of the variable as we go. This results in the following *beautiful* code:

```python
print(
    (
        lambda _, __, ___: (
            lambda ____, _____: _____.whitespace[___].join(
                [
                    frozenset.__name__[:___] + eval.__name__[_] + eval.__name__[_]
                    if ______.count(str(__)) % ___ == _
                    and ______.count(str(_)) % ___ == _
                    else str.__name__[__:]
                    + map.__name__[__:]
                    + type.__name__[___:]
                    + dir.__name__[_]
                    for ______ in [
                        str().join(
                            [
                                bin(ord(________))[___:].zfill(___ * ___ * ___ - __)
                                for ________ in _______.strip()
                            ]
                        )
                        for _______ in ____.stdin.readlines()
                    ]
                ]
            )
        )(
            __import__(str.__name__[_] + type.__name__[__] + str.__name__[_]),
            __import__(str.__name__ + int.__name__[: _ - __] + globals.__name__[_]),
        )
    )(*map(len, [[], [...], [..., ...]]))
)
```

Finally, the most tedious step. Remove all whitespace that you can from the code (including newlines) and you will have the final minified solution:

```python
print((lambda _,__,___:(lambda ____,_____:_____.whitespace[___].join([frozenset.__name__[:___]+eval.__name__[_]+eval.__name__[_]if ______.count(str(__))%___==_ and ______.count(str(_))%___==_ else str.__name__[__:]+map.__name__[__:]+type.__name__[___:]+dir.__name__[_]for ______ in[str().join([bin(ord(________))[___:].zfill(___*___*___-__)for ________ in _______.strip()])for _______ in ____.stdin.readlines()]]))(__import__(str.__name__[_]+type.__name__[__]+str.__name__[_]),__import__(str.__name__+int.__name__[:_-__]+globals.__name__[_])))(*map(len,[[],[...],[...,...]])))
```
