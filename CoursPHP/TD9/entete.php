<!DOCTYPE html>
<html lang="en">
<head>
    <title>Mon site </title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
            crossorigin="anonymous"></script>
    <script src="https://kit.fontawesome.com/1f7457abdb.js"></script>
</head>

<header>
    <div class="jumbotron text-center" style="margin-bottom:0">
        <h1>Site</h1>
        <p></p>
    </div>
</header>
<body>
<!-- A grey horizontal navbar that becomes vertical on small screens -->
<nav class="navbar navbar-expand-sm bg-dark navbar-dark">
    <!-- Links -->
    <ul class="navbar-nav">
        <li class="nav-item">
            <a class="nav-link" href="#">Acceuil</a>
        </li>
        <ul class="navbar-nav">
            <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" role="button" data-bs-toggle="dropdown">Album par catégorie</a>
                <ul class="dropdown-menu">
                    <li><a class="dropdown-item" href="vueCategorie.php?num=1">Fantastique</a></li>
                    <li><a class="dropdown-item" href="vueCategorie.php?num=2">Conte ou légende</a></li>
                    <li><a class="dropdown-item" href="vueCategorie.php?num=3">Humour noir</a></li>
                    <li><a class="dropdown-item" href="vueCategorie.php?num=4">Humour jeunesse</a></li>
                    <li><a class="dropdown-item" href="vueCategorie.php?num=5">Adaptation d'oeuvre littéraire</a></li>
                    <li><a class="dropdown-item" href="vueCategorie.php?num=6">Science-fiction</a></li>

                </ul>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="#">Album par dessinateur</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="#">Album par date de parrution</a>
            </li>
        </ul>
</nav>




