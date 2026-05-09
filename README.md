# Digital System Numbers

A comprehensive project for working with digital system numbers and number system operations.

---

# Features

## 1. Number Base Conversion (2–36)

This section provides advanced number base conversion capabilities with support for both integer and floating-point numbers.

### Capabilities

- Support for bases from **2 to 36**
- Validation of numeric input
- Validation of whether a number is valid in the selected base
- Support for both integer and floating-point numbers
- Convert floating-point numbers from any base to another base `R`
  - Supports precision from **1 to 500,000 decimal digits**
  - If the converted number becomes finite after converting to base 10, the result is exact
  - Otherwise, repeating/infinite fractions may produce approximation errors
- Convert floating-point numbers from base 10 to any base `R`
  - Supports precision from **1 to 500,000 decimal digits**
- Convert floating-point numbers from any base to base 10
  - Supports precision from **1 to 15 decimal digits**
- Formatted output with digit grouping based on the selected base
- Save every conversion result into a `.txt` file on the system

---

## 2. Diminished Radix Complement

## 3. Radix Complement

These sections provide complement calculations for numbers in different bases.

### Capabilities

- Support for bases from **2 to 36**
- Validation of numeric input
- Validation of whether a number is valid in the selected base
- Supports **integer numbers only**

---

## 4. Convert Unsigned Integer Binary to Signed Integer Binary

This section converts unsigned binary integers into signed binary representations using different signed-number methods.

### Capabilities

- Validation of numeric input
- Validation of binary input
- Validation to ensure the entered number is not already negative
- Validation of integer/non-floating-point input
- Ability to manually specify the number of bits
- Support for multiple signed binary representation methods:
  - Signed Magnitude
  - Signed 1's Complement
  - Signed 2's Complement

---

## سیستم اعداد دیجیتال

یک پروژه جامع برای کار با سیستم‌های عددی دیجیتال و عملیات مربوط به مبناهای مختلف.

---

# ویژگی‌ها

## 1. تغییر مبنا (2 تا 36)

این بخش قابلیت‌های پیشرفته‌ای برای تبدیل مبنا ارائه می‌دهد و از اعداد صحیح و اعشاری پشتیبانی می‌کند.

### قابلیت‌ها

- پشتیبانی از مبناهای **2 تا 36**
- بررسی معتبر بودن ورودی عددی
- بررسی اینکه عدد وارد شده در مبنای انتخابی معتبر باشد
- پشتیبانی از اعداد صحیح و اعشاری
- تبدیل اعداد اعشاری از هر مبنایی به مبنای `R`
  - پشتیبانی از دقت **1 تا 500,000 رقم اعشار**
  - اگر عدد پس از تبدیل به مبنای 10 به یک مقدار متناهی تبدیل شود، نتیجه دقیق خواهد بود
  - در غیر این صورت، اعشارهای نامتناهی ممکن است باعث خطای تقریبی شوند
- تبدیل اعداد اعشاری از مبنای 10 به هر مبنای `R`
  - پشتیبانی از دقت **1 تا 500,000 رقم اعشار**
- تبدیل اعداد اعشاری از هر مبنایی به مبنای 10
  - پشتیبانی از دقت **1 تا 15 رقم اعشار**
- نمایش قالب‌بندی‌شده اعداد با تفکیک ارقام بر اساس مبنای انتخابی
- ذخیره هر عملیات تغییر مبنا در فایل `.txt` داخل سیستم

---

## 2. متمم مبنای کاهش‌یافته

## 3. متمم مبنا

این بخش‌ها عملیات محاسبه متمم را برای اعداد در مبناهای مختلف انجام می‌دهند.

### قابلیت‌های این دو بخش

- پشتیبانی از مبناهای **2 تا 36**
- بررسی معتبر بودن ورودی عددی
- بررسی اینکه عدد وارد شده در مبنای انتخابی معتبر باشد
- فقط پشتیبانی از اعداد صحیح

---

## 4. تبدیل اعداد باینری بدون علامت به باینری علامت‌دار

این بخش اعداد باینری بدون علامت را با استفاده از روش‌های مختلف نمایش علامت‌دار تبدیل می‌کند.

### قابلیت‌ها

- بررسی معتبر بودن ورودی عددی
- بررسی باینری بودن عدد وارد شده
- بررسی اینکه عدد وارد شده از ابتدا منفی نباشد
- بررسی صحیح بودن عدد و اعشاری نبودن آن
- امکان تعیین دستی تعداد بیت‌ها
- پشتیبانی از روش‌های مختلف نمایش علامت‌دار:
  - مقدار علامت
  - متمم 1
  - متمم 2