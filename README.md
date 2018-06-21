# Game_Programming_Tutorials

C++ Game Programming practice using content from [Beginning C++ Game Programming](https://www.amazon.co.uk/Beginning-Programming-Premier-Press-Development/dp/1592002056/ref=sr_1_10?s=books&ie=UTF8&qid=1529356234&sr=1-10&keywords=Michael+Dawson)


## Essentials

Integrated Development Environment (IDE) for C++ : 
    
 * [Bloodshed Dev-C++](https://sourceforge.net/projects/orwelldevcpp/) (*Used by the book*)
 * Visual Studio Enterprise 2017 32/64-bit (Multilanguage)
    
## Notes
- **Page 13**: Understanding order of operations (BODMAS)
- **Page 15**: Understanding Type Modifiers
    - *short* and *long* can be assigned when creating primitive data types. Short will reduce the amount of storage space required for a variable, whereas using *long* will increase the amount of storage space required for the variable. 
    - *short* and *long* can *int*. *Long* can modify *double* data types.
    - **Range Modification:** An integer may be *signed* or *unsigned* whilst it is created (only works for int data type). A *signed* int is one which will accept both negtive and positive values, whereas its unsigned counterpart will only accept positive values.
- **Page 20**: Defining new names for datatypes
    - **typedef** *unsigned short int* ushort;
        - keyword **typedef** is used to create a new datatype *ushort* which acts as an alias for the native type '*unsigned short int*' datatype. Allows developers to use alias to shorten the names of these datatypes.
- **Pages 23-24**: Pre- and Post-fix Value Incrementation
    - *Prefix*: ++lives
    - *Postfix*: lives++
    - In practice:
        - Where int lives = 3;
        - *int bonus = ++lives * 10;*
            - Increments a value *before* the evaluation of an expression, such that the value of the variable *lives* will increase by 1 before it is multiplied by 10. In this case lives = **4**. So *4 * 10 = 40*.
        - *int bonus = lives++ * 10;*
            - Increments a value *after* the evaluation of an expression, such that the value of the variable *lives* will increase by 1 after the evaluation of an expression. In this case lives = **3**. So *3 * 10 = 30*. The value 30 will be stored in the int variable *bonus*. After this line of code the value of the variable *lives* will increase from 3 to 4.
- **Page 24**
    - When an integer exceeds it maximum value it will *wrap around* to the lowest value.
    - When an integer is decreased below its minimum value it will *wrap around* to its highest value.
- **Page 27**: Enumerations
    - enum difficulty { NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
        - Starting from the value on the left {0,1,2,3,4}
        -Initialise a variable using the following syntax: difficulty *myvar* = NOVICE; (or any other enum variable from the list).
    - enum ship{FIGHTER = 25, BOMBER, CRUISER = 50, DESTROYER = 100};
        - Value of *BOMBER* is *26* as it is equivalent to the previous value (FIGHTER which is 25) plus 1 = 26.
- **Page 29**: Strings
    - The use of *cin* to get user input only works with *strings* that have no whitespace in them (e.g. tabs and spaces). Use of streams can be used to compensate for this. **Be cautious of the limitations of strings in c++**.
- **Page 39**: If-Statements
    - Non-zero values (including negative values) equate to *true* in an if-statement, therefore, code will be executed within the code block. *0*, on the other hand, equates to *false* in an if-statement, and therefore the compiler will skip and avoid executing the code.
- **Page 44**: Switch Statements
    - Strings **do not** work with switch statements in C++. Integers, chars and enumerators do however.
        
## TroubleShooting
