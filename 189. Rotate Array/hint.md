# Hint

The easiest solution would use additional memory and that is perfectly fine.

The actual trick comes when trying to solve this problem without using any additional memory.
This means you need to use the original array somehow to move the elements around.
Now, we can place each element in its original location and shift all the elements around it to adjust
as that would be too costly and most likely will time out on larger input arrays.

One line of thought is based on reversing the array (or parts of it) to obtain the desired result.
Think about how reversal might potentially help us out by using an example.

The other line of thought is a tad bit complicated but essentially it builds on the idea of
placing each element in its original position while keeping track of the element originally in that position.
Basically, at every step, we place an element in its rightful position and keep track of the element already there or the one being overwritten in an additional variable.
We can't do this in one linear pass and the idea here is based on *cyclic-dependencies* between elements.