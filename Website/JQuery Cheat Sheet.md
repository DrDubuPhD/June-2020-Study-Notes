# jQuery Cheat Sheet

## Table of Contents

- [jQuery Cheat Sheet](#jquery-cheat-sheet)
  - [Table of Contents](#table-of-contents)
  - [Using jQuery](#using-jquery)
  - [Coding in jQuery](#coding-in-jquery)
  - [Selectors & Filters](#selectors--filters)
    - [Basic Selectors](#basic-selectors)
    - [Position Filters](#position-filters)
    - [Content Filters](#content-filters)
    - [Form Filters](#form-filters)
  - [Methods](#methods)
    - [Useful Methods](#useful-methods)
  - [Event Handling](#event-handling)
  - [Effects (Visual)](#effects-visual)
  - [Notable Mentions](#notable-mentions)
  - [`.on()`](#on)

## Using jQuery

> Import from the __CDN__ or __install minified version__

## Coding in jQuery

> To make sure all __DOM Objects are loaded__, run the following within the `<script></script>` tag

```html
<script>
    $(document).ready(function () {
    //code here
    }
</script>
```

> or use this shorter version **(preferred method)**

```html
<script>
    $(function () {
     //code here
    }
</script>
```

## Selectors & Filters

### Basic Selectors

| Syntax        | Description                                      |
|---------------|--------------------------------------------------|
| `$('#ID')`    | Select element based on ID                       |
| `$('tag')`    | Select element based on tag (e.g `<p>`, `<div>`) |
| `$('.class')` | Select element based on class                    |

### Position Filters

| Pseudoclass | Description                                                               |
|-------------|---------------------------------------------------------------------------|
| `:first`    | e.g. `$('li a:first')` selects the first `<a>` within the `<li>`          |
| `:last`     | e.g. `$('li a:last')` selects the last `<a>` within the `<li>`            |
| `:even`     | e.g. `$('li a:even')` selects all even positioned `<a>` within the `<li>` |
| `:odd`      | e.g. `$('li a:odd')` selects the odd positioned `<a>` within the `<li>`   |

### Content Filters

| Pseudoclass       | Description                                                          |
|-------------------|----------------------------------------------------------------------|
| `:contains(text)` | e.g. `$('li a:contains("test")')`, selects `<a>` that has **"test"** |
| `:empty`          | e.g. `$('div:empty')` selects all `<div>` that has no children       |
| `:has(selector)`  | e.g. `$('div:has("p")')` selects all `<div>` that contains `<p>`     |
| `:parent`         | e.g. `$('div:parent')` selects all `<div>` that are parents          |

### Form Filters

| Pseudoclass | Description                                                                                     |
|-------------|-------------------------------------------------------------------------------------------------|
| `:checkbox` | e.g. `$('form input:checkbox')`, selects all `<input type = "checkbox">`                        |
| `:checked`  | e.g. `$('form input:checked')` selects all checkboxes or radio that are ticked                  |
| `:disabled` | Selects all elements with the `disabled` attribute                                              |
| `:enabled`  | Selects all elements without the `disabled` attribute                                           |
| `:file`     | Selects all `<input type = "file">`                                                             |
| `:focus`    | Selects elements that have the focus that match the selector                                    |
| `:image`    | Selects all `<input type = "type">`                                                             |
| `:input`    | Selects all `<input>` element within form                                                       |
| `:password` | Selects all `<input type = "password">`                                                         |
| `:radio`    | Selects all `<input type = "radio">`<br>**Very Useful**                                            |
| `:reset`    | Selects all `<input type = "reset">`                                                            |
| `:selected` | Selects all `<option>` elements that selected                                                   |
| `:submit`   | Selects all `<input/button type = "submit">`                                                    |
| `:text`     | Selects all `<input type = "text">` or `<input>` without types (`type = "type"` is the default) |

- Most jQuery syntax begin with `$()`
- jQuery selectors are **based on CSS selectors**
- jQuery **accepts single-quotes** `'literal'` as string containers

## Methods

> Once we selected an element, we can **perform actions (use methods)**

Example:

> `$("#div1").addClass("red")` (adds the attribute of `class = "red"` for the selected element)

### Useful Methods

| Methods      | Purpose                                                                                                              |
|--------------|----------------------------------------------------------------------------------------------------------------------|
| `css()`      | Takes 2 args, 1st arg is the *property*, 2nd arg is the *value*                                                      |
| `attr()`     | If 1 arg (attribute), returns the value of the arg<br>If 2 args(attribute, value), sets the value to the attribute   |
| `html()`     | Can be assigned to a `var` to get the html **OR**<br>Pass in 1 arg, which is the string to be set inside the element |
| `text()`     | Same as `html()`, however it get/set text only                                                                       |
| `val()`      | Get/Set the value of form fields                                                                                     |
| `prepend()`  | Inserts HTML inside the element at start                                                                             |
| `append()`   | Inserts HTML inside the element at end                                                                               |
| `before()`   | Insert HTML outside before the selected element                                                                      |
| `after()`    | Insert HTML outside after the selected element                                                                       |
| `appendTo()` | Moves all selected elements somewhere, takes in a selector as arg                                                    |

## Event Handling

| Method (Event Handlers) | Purpose                                                                         |
|-------------------------|---------------------------------------------------------------------------------|
| `click()`               | Binds a event handler to the selected element, usually as an anonymous function |
| `focus()`               | Executes when a **form field** has focus                                        |
| `hover()`               | Executes during `onmouseover` event                                             |
| `mousedown()`           | Executes when the mouse is pressed down on the selected element                 |
| `toggle()`              | Show/Hide the selected element                                                  |
|`submit()`| Refers to the **form submit event**, usually will be used with `e.preventDefault()`|

## Effects (Visual)

| Method          | Purpose                                                   |
|-----------------|-----------------------------------------------------------|
| `fadeToggle()`  | Show/Hide the selected element by animating their opacity |
| `slideToggle()` | Show/Hide the selected element with a sliding motion      |
| `show()`        | Shows an originally hidden element                        |
| `hide()`        | Shows an originally visible element                       |

## Notable Mentions

## `.on()`

> Attaches **1 or more event handlers** for the selected elements and child elements

`$(selector).on(event, childSelector, data, function, map)`

> To attach an event that only runs once, use `one()`

`$(selector).one(event, childSelector, data, function, map)`

>To remove an event handler, use `off()`

`$(selector).off()`

| Parameters      | Description                                                                                                      |
|-----------------|------------------------------------------------------------------------------------------------------------------|
| `event`         | **(Required)** Specify 1 or more events, must be valid event.<br>Multiple events are seperated by space          |
| `childSelector` | (Optional) Will attach only to the selected child                                                                |
| `data`          | (Optional) Additional data to be passed into the function                                                        |
| `function`      | **(Required)** Event Handler code                                                                                |
| `map`           | Event Map `({event1:function, event2:function,...})`, functions will be executed according to their mapped event |