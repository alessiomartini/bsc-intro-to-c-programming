# Introduction to Informatics — C Programming Course (UniMiB)

Material from the *Informatica* course, BSc in Physics, Università degli Studi
di Milano-Bicocca, spring **2021** (lecturer: F. Nati, group L-Z / M-Z) —
Alessio Martini.

A small archive: the lecture slides, the two C programs written during the
course, and the exercise sheets with their input data. The course teaches C from
the ground up, in the style of Kernighan & Ritchie, to physics students who
mostly have not programmed before.

Comments and lecture material are in Italian.

## The C programs

### `fahrcels.c` — the first program

The Fahrenheit-to-Celsius conversion table from *The C Programming Language*
(Kernighan & Ritchie), adapted for the course. A `while` loop, a formatted
`printf`, and the classic first lesson of the book: integer division would give
the wrong answer, so the conversion factor is written `5.0/9.0` and not `5/9`.

### `868915-Au.c` — the exam-style exercise

A weather-station log processor, and a genuine small program rather than an
exercise in syntax. It reads a day's worth of sensor packets from standard
input in the form `<seconds>S<ADU>T`, where the second field is a raw
analog-to-digital reading, and:

- converts each ADU count to a temperature in Celsius through the sensor's
  calibration line, `temp = ADU · 160/255 − 50`;
- classifies each reading by the band it falls into — `OMBRA` (shade) for
  −22 °C … −14 °C, `SOLE` (sun) for 74 °C … 82 °C — and discards everything else;
- stores the surviving readings in an array of `struct Pacchetto`, indexed by
  the timestamp in seconds, one slot per second of the day (`T = 86400`);
- prints the day back out in chronological order.

It exercises exactly what the course is assessed on: `struct`, arrays as
storage indexed by a meaningful key, `scanf` with a custom format, `strcpy` for
fixed-size strings, and separating a conversion function from the control flow
that uses it.

## Exercise sheets and data

| File | Content |
| --- | --- |
| `Esercitazioni/lif-e7-21.pdf` | Exercise sheet 7 |
| `eser7comm.pdf`, `eser7fin.pdf` | The worked solution to exercise 7 — commented version and final version |
| `comp1.txt`, `comp2.txt` | The input data for it: colon-separated records, `name:languages:sports:age`, with comma-separated lists inside two of the fields (`Carlo:inglese,francese:sci,tennis:27`). Parsing this format — nested separators, empty fields, names containing spaces — *is* the exercise |

## Lecture slides

`Lezioni/` holds five lecture PDFs by F. Nati, from 3 March to 21 April 2021,
one slide per page.

## Building and running

Nothing to configure — single-file programs, no dependencies:

```bash
gcc -o fahrcels fahrcels.c && ./fahrcels
gcc -o au 868915-Au.c && ./au < input.txt
```

`868915-Au.c` expects exactly `N = 25` packets on standard input, in the format
described above.

## Note

The `desktop.ini` files are Windows folder-metadata leftovers and carry no
course content.

## Related repositories

- [`bsc-computational-physics-exercises`](https://github.com/alessiomartini/bsc-computational-physics-exercises)
  — where this C ends up being used: twenty numerical-methods exercises.
- [`archive-highschool-programming`](https://github.com/alessiomartini/archive-highschool-programming)
  — the earlier, high-school programming archive (Python, web, Raspberry Pi).
