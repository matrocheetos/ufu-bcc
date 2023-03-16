p(1).
p(2).
p(3).
p(4).
p(5).
p(6).
p(7).
p(8).

c(L1,C1,[L2,C2]) :-   L2 is L1 +1, C2 is C1 +2;
                        L2 is L1 +1, C2 is C1 -2;
                        L2 is L1 -1, C2 is C1 +2;
                        L2 is L1 -1, C2 is C1 -2;
                        L2 is L1 +2, C2 is C1 +1;
                        L2 is L1 +2, C2 is C1 -1;
                        L2 is L1 -2, C2 is C1 +1;
                        L2 is L1 -2, C2 is C1 -1.


objetivo(Lc,Cc,[L,C]) :-    c(Lc,Cc,[L,C]), \+L==Lc+1;
                            c(Lc,Cc,[L,C]), L==Lc+1.
