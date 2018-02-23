<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>LSConsole</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css"
          integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">
    <link rel="stylesheet" href="../css/style.css">
</head>
<body>
<form action="executa.php" method="post">
    <main class="container-fluid">
        <section>
            <h3>LSConsole - Simulació de terminal amb Php i Bootstrap</h3>
            <p>
                <span> Pressiona 'help' + <kbd>Enter</kbd> per veure les comandes disponibles</span>
            </p>
        </section>

        <div class="row">
            <span class="command" class="col-xs-2 col-sm-2 col-md-4">
            dani&javi:/$
            </span>

            <input class="col-xs-10 col-xs-10 col-md-8" type="text" name="input_cmd" autofocus spellcheck="false"
                   autocomplete="off">
        </div>
    </main>
</form>

<script
        src="http://code.jquery.com/jquery-3.3.1.min.js"
        integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8="
        crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js"
        integrity="sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn"
        crossorigin="anonymous"></script>
</body>
</html>
