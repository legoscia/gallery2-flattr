{if empty($item)} {assign var=item value=$theme.item} {/if}

{g->callback type="flattr.GetPhoto" itemId=$item.id}

{if $block.flattr.isPhoto}
{include file="gallery:modules/flattr/templates/FlattrButton.tpl"
	 FlattrTitle=$item.title
	 FlattrUsername=$block.flattr.username
	 FlattrUrl=$block.flattr.url
	 FlattrDescription=$item.description}
{/if}
