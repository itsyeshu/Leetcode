# Hint

As there doesn't exist a single DS to show in average O(1) constant time insersion, deletion and Randomized access, without duplication.

To overcome this issue, you need to use 2 or more DS in sync ith each other. Let's look at candidates:
* O(1) Insersion and randmized access can be achieved with Arrays or to be Specific Vector
    ***Problems:***
    * How to delete at any index?
    * How to avoid duplication?
* Above mentioned problems can be solved by a DS. That DS is *Hash table*.
    ***How it solves above problems:***
    * How to delete at any index?
    => Deletion at the last index of array is O(1)
    * How to avoid duplication?
    => Use HashTable to keep track of the available elements in the array.

And thus you can achieve, O(1) insertion, deletion and random access.