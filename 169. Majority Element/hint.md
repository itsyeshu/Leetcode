# Hint

You need to use hashmap to note the total occurences of each element and return the element with highest occured element.
This approach takes O(n) space complexity. Can we do better?

Actually we can. By using clever algorithm - Moore's voting algorithm.
It is based on the fact that, the majority element occures more than other elements combined.