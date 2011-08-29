
<div class="gbBlock gcBackground1">
  <h2> {g->text text="Flattr configuration"} </h2>
</div>

<div class="gbBlock">
  For the Flattr button to work, you need to fill in your Flattr username.
  If you haven't got one already, you can register at
  <a href="http://flattr.com">flattr.com</a>.
</div>

<div class="gbBlock">
{if $Flattr.username}
Flattr buttons on your photos currently point to Flattr user
<a href="http://flattr.com/profile/{$Flattr.username}">{$Flattr.username}</a>.
{else}
No Flattr username has been configured yet.
{/if}
</div>

<form action="{g->url}" method="post">
  <div>
    {g->hiddenFormVars}
    <input type="hidden" name="{g->formVar var="controller"}" value="flattr.Flattr"/>
    <input type="hidden" name="{g->formVar var="form[formName]"}" value="{$form.formName}"/>
  </div>

  <div class="gbBlock">
    <label>{g->text text="Enter your Flattr username:"}
    <input type="text" name="{g->formVar var="form[flattrUsername]"}"/>
    </label>
  </div>

  <div class="gbBlock gcBackground1">
    <input type="submit" class="inputTypeSubmit"
      name="{g->formVar var="form[action][save]"}" value="{g->text text="Save"}"/>
  </div>
</form>

