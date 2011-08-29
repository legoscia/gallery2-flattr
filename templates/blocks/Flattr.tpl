{if empty($item)} {assign var=item value=$theme.item} {/if}
<p>This is the item: {$item}</p>

{foreach from=$item key=key item=x}
<p>This is an individual item: {$key} → {$x}</p>
{/foreach}

{g->callback type="flattr.GetPhoto" itemId=$item.id}

{if $block.flattr.isPhoto}
<p>This is a photo!</p>

<p>This is where the Flattr button goes 🙌</p>

<a class="FlattrButton" style="display:none;"
    title="{$item.title}"
    rev="flattr;uid:{$block.flattr.username};category:images;"
    href="{$block.flattr.url}">
{$item.description}
</a>

<p>This is the URL we used: {$block.flattr.url}</p>

{else}
<p>This is not a photo.  Probably won't put a Flattr button here…</p>

<p>Return value: '{$block.flattr.isPhoto}'</p>
{/if}

<p>This is something else: '{$block.flattr.foobar}'</p>
