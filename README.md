# Assignment 2

## Task

Some information on the Internet may be encrypted with a simple algorithm known as **rot13**, which rotates each character by 13 positions in the alphabet.
A **rot13** cryptogram is a message or word in which each letter is replaced with another letter that comes from a position in the alphabet moved from the original letter position at a constant displacement value, e.g. 13 letters forward.

- **rot13** is an example of symmetric key encryption.

For example, the string

        the bird was named squawk

might be scrambled to form

        cin vrjs otz ethns zxqtop

### Details

1. Write missing method implementations for the class `Rot13` that get a functional ROT13 cipher.

2. The input plain or encrypted message string is placed into the `Rot13` object during the initialization.
    - The input string may only contain Latin lowercase letters and spaces. You must check if the input string is valid before storing the input in the `text` field. If the input is invalid, the `text` field must be left empty.

3. Overload the bang operator `!` to check if the `Rot13` object is correctly initialized, and contains a non-empty message.
    - The operator returns `true` if the message is empty.

4. Overload the stream extraction operator `>>` for the `Rot13` class to perform **rot13** encryption.
    - The operator has to be implemented as a member function with a (modifiable) string reference parameter which is used to store an encrypted message.
    - Encrypt the message stored in the string field `text`, and place it in the method reference parameter.
      - The encryption procedure replaces every occurrence of the character with the character 13 steps forward in the alphabet (in a circular way). For example, `a` with `n` , `b` with `o` , and `x` with `k`, and so on.
      - Spaces are not scrambled.
      - Use `static_cast<>` operator to transform characters into numbers which would allow to perform rotation transformation using addition/subtraction operations.
      - You can find numerical codes for letters in [ASCII Table](https://en.wikipedia.org/wiki/ASCII#Printable_characters)

5. Overload the insertion operator `<<` for the `Rot13` class to perform decryption of the ROT13 cipher into the original message.
    - Because ROT13 is a symmetric key encryption, the decryption process is a exact reversal of the encryption. The decryption replaces every occurrence of the character with the character 13 steps backward in the alphabet (in a circular way).
    - Spaces are not scrambled.

6. You can add any number of additional methods into the class for better code reuse.

7. All method implementations must be outside the class declaration.

## Test

Press **Run** button to execute and test your program.

- Or run `make test` command in the command line to verify the correctness of your program.

## Submission

- Commit & push all changes that to the corresponding assignment repository on GitHub, using the **Repl.it** interface - **Version control** tab.
  - Make sure that you committed changes to following files:
    - `main.cpp`
- Submit the link of the assignment GitHub repository in the corresponding assignment submission the Blackboard.
  - Open corresponding assignment on the Blackboard
  - In **Assignment Submission** section, press **Write Submission** button
  - Paste your assignment repository link in the **Text Submission** box
  - Submit the assignment

### Before You Submit

You are required to test that your submission works properly before submission. Make sure that your program compiles without errors. Once you have verified that the submission is correct, you can submit your work.

### Coding Style

In any programming project, matching the existing coding style is important. Having different coding styles intermixed leads to confusion and bugs. Students are required to follow the particular existing coding style that maintains the indentation style in `.cpp` and `.h` files using spaces, not tabs.

In particular, pay close attention to function declarations and how the function name begins the line after the function return type. For helper functions which are limited in scope to a specific file, you must declare the function as `static` in the same file in which it is used.

*Indentation*: The indentation style for your work have to be 4 spaces. Many students are taught to use tabs for indentation, which can make code very hard to read, especially when there are several levels of indentation.

For additional information of C++ coding style see [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

