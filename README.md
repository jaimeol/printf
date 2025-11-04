# 🖨️ ft_printf

> A custom implementation of the C standard `printf` function — exploring variadic arguments, format parsing, and output formatting.

---

## 🧠 Overview
`ft_printf` is a **recreation of the standard C library’s `printf` function**, built from scratch as part of the 42 curriculum.  
The goal is to understand how formatted output works internally — from parsing format specifiers to managing variable arguments and type conversions.

---

## ⚙️ Implementation
Supported conversions include:
- `%c` — Character  
- `%s` — String  
- `%p` — Pointer address  
- `%d` / `%i` — Signed integers  
- `%u` — Unsigned integers  
- `%x` / `%X` — Hexadecimal representation  
- `%%` — Literal `%` character  

Key features:
- Handling **variadic arguments** with `<stdarg.h>`  
- Building a **modular parsing system** for format specifiers  
- Implementing **buffered output** for efficiency  

---

## 🧠 Reflection
Although the project may seem simple, `ft_printf` bridges the gap between basic C syntax and more complex systems programming — it’s where manual memory management meets elegant string formatting.
