<?php
include "entete.php";
?>
<section>
        <div class="container" style="margin-top:30px">
            <div class="row">
                <div class="col-sm-4">
                <img  src="images/logo.webp" width=80 height= 80 >
                </div>      
                <div class="col-sm-8">
                <form action = "traitCnx.php" method = "post">
                  <div class="form-group">
                      <label for="EmailDemo">Votre mail :</label>
                     <input type="email" class="form-control" name="mail" aria-describedby="emailHelp" placeholder="Enter email">
                     <small id="emailHelp" class="form-text text-muted">Votre mail</small>
                 </div>
                 <div class="form-group">
                        <label for="passDemo">Votre mot de passe : </label>
                     <input type="password" class="form-control" name="pass" aria-describedby="passHelp" placeholder="Password">
                     <small id="passHelp" class="form-text text-muted">Must be 8 characters long</small>
                 </div>
                    <button type="submit" class="btn btn-success">Se connecter</button>
                </form>
                </div>
        </div>
    </div>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>