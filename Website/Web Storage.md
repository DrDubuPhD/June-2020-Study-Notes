# Web Storage

## Cookies

```javascript
document.cookie = "username=John Doe; expires=Thu, 18 Dec 2013 12:00:00 UTC";
```

- Delete a cookie by setting past date
- Retrieve a cookie using the function in VSCODE
- `escape()` and `unescape()`

## localStorage and sessionStorage

Check for storage availability

```javascript
if (typeof(Storage) != 'undefined') {
    localStorage.setItem("lastname", "Smith");
    sessionStorage.setItem("firstname", "John");
    
    var str1 = localStorage.getItem('lastname');
    var str2 = sessionStorage.getItem('firstname');
    
    localStorage.removeItem('lastname');
}
```

