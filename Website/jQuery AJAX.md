# jQuery AJAX

`load()`, `$.get()`, `$.post()` are methods provided

`HTTP GET and POST` are used for loading and sending data to servers

## Load() Method

```javascript
$(selector).load(URL, data, complete);
```

The above code places the returned HTML into the selected element

- `URL` - required
- `data` - optional, key/value pairs that are sent to the server
- `complete` - optional, callback function that executes for each selected element.
  - `responseTxt` - contains resulting content if the request succeeds.
  - `statusTxt` - contains the status of request such as success or error
  - `jqXHR` - contains the XMLHttpRequest object

To load part of the URL use:

```javascript
$('#box').load('test-content.html #hint');
```

## REST APIs

Use the `$.get()` and `$.post()` methods to perform AJAX actions

```javascript
$.get(URL, data, success); or $.post(URL, data, success);
```

- `URL` - required
- `data` - optional, same
- `success` - executes when the request succeeds. Used to retrieve returned data.

```javascript
$.get('https://...', {"id" : 4}, function(data){
    //Display the returned object in the data
    $('#result').html(data);
});
```

`jqXHR.done()`

`jqXHR.fail()`

`jqXHR.always()`

### Shorthand AJAX

```javascript
$.ajax({
    type : "POST",
    url : url,
    data : data,
    success : success,
    dataType : dataType
});
```

### Retrieving JSON Objects

```javascript
$.getJSON(url, data, callback);
```

Same as

```javascript
$.ajax({
    dataType: "json",
    url : url,
    data : data,
    success : success
})
```

## Example Code

```javascript
$.getJSON('https://')
.done(function (jd){
    //code here
})
.fail(function () {
    //code here
});
```

## data-*

A custom HTML attribute that stores custom data

**Criteria**

`data-name = value`

`name`

- must not contain uppercase
- at least 1 char long

`value`

- any string

```javascript
$(this).data("id") //access data-id = ...
$(this).attr("data-id") //same
```

