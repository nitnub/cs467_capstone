
Run ./run_mixer.sh to test.


# A quick note on the Space Invaders sounds

The files under /sounds are the same sounds we resourced online, however-

The invaderkilled.wav sounds like the shooting effect and vice versa - it seems like they were labeled wrong.

fastinvader1-4 are supposed to form a “walking bass” that gets faster as the enemy is closer. The files would play a descending stepwise bass motion, each file being a single step. However, in the set we downloaded, fastinvader4.wav had the highest pitch (rather than the lowest), which doesn’t make sense in terms of their intended order. I renamed fastinvader4 as fastinvader0 so that it can be loaded in order.

Here’s a reference for sounds: 
https://www.youtube.com/watch?v=Sx0ZcT2fY0U

Which seems to be fitting to the actual machine’s sounds, if you’d like to compare:
https://www.youtube.com/watch?v=1uSzmzZP1s8
