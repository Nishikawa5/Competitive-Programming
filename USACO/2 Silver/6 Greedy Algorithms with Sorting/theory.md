### General rule
(local optimal -> local optimal -> ... -> local optimal) generates a global optimal

### Best number of intervals
pick the intervals that finishes first

### Tasks and deadlines
given: n tasks w/ durations and deadlines. We eand d - x points where d is the deadline and x is the moment we finish the task
want: get the largest possible total score

perform tasks sorted by durations in increasing order

### Minimize sums
minimize: |a1 − x|^c + |a2 − x|^c + ··· +|an − x|^c
want: find x that minimizes the sum
for c = 1:
just get the median of all numbers

