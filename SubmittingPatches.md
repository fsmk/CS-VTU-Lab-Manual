# Guidelines For Contribution

Here are some guidelines for people who want to contribute their code
to this software. Heavily borrowed from Git.

## 1. Make separate commits for logically separate changes.

Unless your patch is really trivial, you should not be sending
out a patch that was generated between your working tree and
your commit head.  Instead, always make a commit with complete
commit message and generate a series of patches from your
repository.  It is a good discipline.

Give an explanation for the change(s) that is detailed enough so
that people can judge if it is good thing to do, without reading
the actual patch text to determine how well the code does what
the explanation promises to do.

If your description starts to get too long, that's a sign that you
probably need to split up your commit to finer grained pieces.
That being said, patches which plainly describe the things that
help reviewers check the patch, and future maintainers understand
the code, are the most beautiful patches.  Descriptions that summarise
the point in the subject well, and describe the motivation for the
change, the approach taken by the change, and if relevant how this
differs substantially from the prior version, are all good things
to have.

## 2. Describe your changes well.

The first line of the commit message should be a short description and
should skip the full stop. Prefix the commit with the "area:" where the
area is  the filename identifier in general being modified, e.g.,

     V/4/MP/11Floyd: Improve efficiency of the algorithm

Where,

* _V_ represents VTU
* _4_ represents the 4th semester
* _MP_ represents the name of the lab
* _11Floyd_ represents the no and name of the program

Another example would be,

     V/6/USP/6System: Make parent wait for child

Pull requests failing to fall by this pattern will be frowned upon.

The body should provide a meaningful commit message, which:

* explains the problem the change tries to solve, i.e., what is wrong
  with the current code without the change.

* justifies the way the change solves the problem, i.e., why the
  result with the change is better.

* mentions alternate solutions considered but discarded, if any.

Describe your changes in imperative mood, e.g. "make xyzzy do frotz"
instead of "[This patch] makes xyzzy do frotz" or "[I] changed xyzzy
to do frotz", as if you are giving orders to the codebase to change
its behaviour.  Try to make sure your explanation can be understood
without external resources.
