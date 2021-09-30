### What is this?

This is a small program to parse a file that follows this convention:

{title}
{description}
{date}
{content}

I originally used that format for the static site builder (written in Go) I use for my [website](https://michaelspangler.io). As an exercise I wrote this small C program to parse the file into structs.

### What I learned

For me, this solidified how pointers work when manipulating strings.

While it's a simple implementation, hopefully it will be useful to someone trying to learn more about pointers.
