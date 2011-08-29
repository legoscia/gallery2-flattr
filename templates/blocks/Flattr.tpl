{if empty($item)} {assign var=item value=$theme.item} {/if}

{g->callback type="flattr.GetPhoto" itemId=$item.id}

{if $block.flattr.isPhoto}
<a class="FlattrButton" style="display:none;"
    title="{$item.title}"
    rev="flattr;uid:{$block.flattr.username};category:images;"
    href="{$block.flattr.url}">
{$item.description}
</a>
{/if}
