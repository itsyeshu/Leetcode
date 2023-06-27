# Hint

## 1. Using Prefix and Suffix product
Use *prefix product* and *suffix product* for each index of `nums` array and multiply them together to get the *Product of Array except self*.
Can you merge the last 2 steps of creating *suffix product* and multiplying them together?

This method has O(N) *space complexity*. Can we do better?

## 2. Using divison : O(1) Space Complexity
>***Note*** : Question explicitely asks not to use *divison*
You store the `product` of all elements in `nums`, and store `product/nums[i]` for each `i` in answer array.
You can't divide by Zero, so what if there is a `0 (zero)` or a bunch of `zeros` in `nums`?
Also, `product` definitely exceeds the boundary of **32-bit** integer?

### ***Think about it***
- If there is a zero in `nums` array, except for that element all the answer array elements will be zero. And that element will be equal to `product`.
- If there are multiple zeros, all the answer array elements will be zero.
- We will use A long integer which is enough for the `product` of all elements in `nums`.

## 3. Optimized solution : Using Prefix and Suffix product
As discussed in [Hint 1](#1-using-prefix-and-suffix-product), calculate the prefix sum and suffix product, but use the `answer` array to store this products.

>***Note***:
>Extra space is only allocated for the `answer(output)` array, however the output *does not count* towards the *space complexity*.