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
        
## TroubleShooting
