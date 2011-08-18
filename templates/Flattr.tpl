
<div class="gbBlock gcBackground1">
  <h2> {g->text text="My First Page"} </h2>
</div>

<div class="gbBlock">
  Hello, my name is <b>Magnus</b>.  This is my first Gallery 2 page!
</div>

<div class="gbBlock">
  The item you chose for this action was: <b>{$Flattr.item.title|default:$Flattr.item.pathComponent}</b>
</div>
<div class="gbBlock">
  {if empty($Flattr.value)}
  There is no value yet for this item.
  {else}
  The value in the database for this item is: <b>{$Flattr.value}</b>
  {/if}
</div>

<form action="{g->url}" method="post">
  <div>
    {g->hiddenFormVars}
    <input type="hidden" name="{g->formVar var="controller"}" value="flattr.Flattr"/>
    <input type="hidden" name="{g->formVar var="form[formName]"}" value="{$form.formName}"/>
    <input type="hidden" name="{g->formVar var="itemId"}" value="{$Flattr.item.id}"/>
  </div>

  <div class="gbBlock">
    {g->text text="Enter a value for this item:"}
    <input type="text" name="{g->formVar var="form[value]"}"/>
  </div>

  <div class="gbBlock gcBackground1">
    <input type="submit" class="inputTypeSubmit"
      name="{g->formVar var="form[action][save]"}" value="{g->text text="Save"}"/>
  </div>
</form>

