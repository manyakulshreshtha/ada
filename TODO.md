# TODO - lab8/heap.c fixes

- [x] Review current compilation/runtime issue (likely VLA usage).
- [x] Update `heap.c` to remove VLA (`int arr[n]`) by using `malloc`.
- [x] Add input validation for `scanf` and handle `n <= 0` safely.
- [x] Add `free(arr)` before exit.
- [x] Rebuild and run basic tests (n=0, n=1, n>1).
- [ ] Verify no compiler warnings/errors from the changes.


