# Help

## Running the tests

Get the first test compiling, linking and passing by following the [three rules of test-driven development][3-tdd-rules].

The included makefile can be used to create and run the tests using the `test` task.

```console
$ make test
```

Create just the functions you need to satisfy any compiler errors and get the test to fail.
Then write just enough code to get the test to pass.
Once you've done that, move onto the next test.

As you progress through the tests, take the time to refactor your implementation for readability and expressiveness and then go on to the next test.

Try to use standard C99 facilities in preference to writing your own low-level algorithms or facilities by hand.

[3-tdd-rules]: https://blog.cleancoder.com/uncle-bob/2014/12/17/TheCyclesOfTDD.html

## Resources

To get help if having trouble, you can use the following resources:

- [StackOverflow][] can be used to search for your problem and see if it has been answered already. You can also ask and answer questions.
- [CPPReference][] can be used to look up information on C concepts, operators, types, standard library functions and more.
- [TutorialsPoint][] has similar content as CPPReference in its C programming section.
- [The C Programming][K&R] book by K&R is the original source of the language and is still useful today.

[c-track]: https://exercism.org/docs/tracks/c
[stackoverflow]: http://stackoverflow.com/questions/tagged/c
[cppreference]: https://en.cppreference.com/w/c
[tutorialspoint]: https://www.tutorialspoint.com/cprogramming/
[K&R]: https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628/